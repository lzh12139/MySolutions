// BM算法，通过给前n项，可以求最短的递推式
// 用NTT优化，可以在O(nlogn)的效率下求得第N项
// 对模数有要求，需要是能用NTT解决的
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> V;
ll quick_mul(ll a,ll b,ll mod){
	return (a-b-(ll)((long double)a/mod*b)*mod+mod)%mod;
}
ll quick_pow(ll base,ll b,ll mod){
	ll res=1;
	while(b){
		if(b&1)res=res*base%mod;
		base=base*base%mod;
		b>>=1;
	}
	return res;
}
ll get_inv(ll x,ll mod){return quick_pow(x,mod-2,mod);}
namespace NTT{
	const int N=20000;
	const int g=3;
	int rev[2*N+10];
	ll ntta[2*N+10],nttb[2*N+10];
	int getrev(int len){
		int bit=0,n=1;
		while((1<<bit)<len)bit++;
		for(int i=0;i<len;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
		return 1<<bit;
	}
	void ntt(V &x,int len,int opt,ll mod){
		if(abs(opt)!=1)printf("-----error:opt:%d\n",opt);/////////////
		for(int i=0;i<len;i++)
			if(i<rev[i])swap(x[i],x[rev[i]]);
		for(int mid=1;mid<len;mid<<=1){
			ll tmp=quick_pow(g,(mod-1)/(mid*2),mod);
			if(opt==-1)tmp=quick_pow(tmp,mod-2,mod);
			for(int i=0,add=mid<<1;i<len;i+=add){
				ll base=1;
				for(int j=i;j<i+mid;j++,base=base*tmp%mod){
					int a=x[j],b=base*x[j+mid]%mod;
					x[j]=(a+b)%mod,x[j+mid]=(a-b+mod)%mod;
				}
			}
		}
		if(opt==-1){
			int optmod=quick_pow(len,mod-2,mod);
			for(int i=0;i<len;i++)x[i]=x[i]*optmod%mod;
		}
	}
	V solve(const V &a,const V &b,int lena,int lenb,ll mod){
		int len=1;
		while(len<lena+lenb)len<<=1;
		getrev(len);

		V ntta=a,nttb=b;
		ntta.resize(len);nttb.resize(len);

		ntt(ntta,len,1,mod),ntt(nttb,len,1,mod);
		for(int i=0;i<len;i++)ntta[i]=ntta[i]*nttb[i]%mod;
		ntt(ntta,len,-1,mod);

		return ntta;
	}
}
namespace MTT{
	ll mod[3]={998244353,469762049,1004535809};
	V MTT(V a,V b,ll MOD){
		V res0=NTT::solve(a,b,a.size(),b.size(),mod[0]);
		V res1=NTT::solve(a,b,a.size(),b.size(),mod[1]);
		V res2=NTT::solve(a,b,a.size(),b.size(),mod[2]);

		ll M1=mod[0]*mod[1];
		ll IM0=quick_pow(mod[0],mod[1]-2,mod[1]);
		ll IM1=quick_pow(mod[1],mod[0]-2,mod[0]);
		V res(a.size()+b.size(),0);

		for(int i=0;i<a.size()+b.size();i++){
			ll c=(quick_mul(res0[i]*mod[1],IM1,M1)+quick_mul(res1[i]*mod[0],IM0,M1))%M1;
			ll x=((res2[i]-c)%mod[2])%mod[2]*quick_pow(M1,mod[2]-2,mod[2])%mod[2];
			res[i]=(x*(M1%MOD)%MOD+c)%MOD;
		}
		return res;
	}
	V MTT(V a,int opt,ll MOD){
		V res0=a,res1=a,res2=a;
		NTT::ntt(res0,a.size(),opt,mod[0]);
		NTT::ntt(res1,a.size(),opt,mod[1]);
		NTT::ntt(res2,a.size(),opt,mod[2]);

		ll M1=mod[0]*mod[1];
		ll IM0=quick_pow(mod[0],mod[1]-2,mod[1]);
		ll IM1=quick_pow(mod[1],mod[0]-2,mod[0]);
		V res(a.size(),0);

		for(int i=0;i<a.size();i++){
			ll c=(quick_mul(res0[i]*mod[1],IM1,M1)+quick_mul(res1[i]*mod[0],IM0,M1))%M1;
			ll x=((res2[i]-c)%mod[2])%mod[2]*quick_pow(M1,mod[2]-2,mod[2])%mod[2];
			res[i]=(x*(M1%MOD)%MOD+c)%MOD;
		}
		return res;
	}
}
V get_inv(const V &a,ll mod){
	V res(1,get_inv(a[0],mod)),inv;
	int inf=1;
	while(inf<=a.size())inf<<=1;
	for(int i=2;i<inf;i<<=1){
		int len=NTT::getrev(i<<1);
		inv=a;inv.resize(len);res.resize(len);

		for(int j=i;j<len;j++)inv[j]=0;
		inv=MTT::MTT(inv,1,mod);
		res=MTT::MTT(res,1,mod);
		for(int j=0;j<len;j++)
			res[j]=(2-inv[j]*res[j]%mod+mod)%mod*res[j]%mod;
		res=MTT::MTT(res,-1,mod);
		for(int j=i;j<len;j++)res[j]=0;
	}
	res.resize(a.size());
	return res;
}
V Vadd(const V &a,const V &b,ll mod){
	V res=a;res.resize(max(a.size(),b.size()));
	for(int i=0;i<b.size();i++)res[i]=(res[i]+b[i])%mod;
	return res;
}
V Vsub(const V &a,const V &b,ll mod){
	V res=a;res.resize(max(a.size(),b.size()));
	for(int i=0;i<b.size();i++)res[i]=(res[i]-b[i]+mod)%mod;
	return res;
}
V Vmul(const V &a,const V &b,ll mod){
	return MTT::MTT(a,b,mod);
}
V Vdiv(const V &a,const V &b,ll mod){
	V res=a,x=b;
	reverse(res.begin(),res.end());
	reverse(x.begin(),x.end());
	int sz=1,deg=a.size()-b.size()+1;
	while(sz<=deg)sz<<=1;
	x.resize(sz);
	x=get_inv(x,mod);
	x.resize(deg);
	res=Vmul(res,x,mod);
	res.resize(deg);
	reverse(res.begin(),res.end());
	return res;
}
V Vmod(const V &a,const V &b,ll mod){
	V res=Vsub(a,Vmul(Vdiv(a,b,mod),b,mod),mod);
	res.resize(b.size()-1);
	return res;
}
namespace BM{
	const int N=20000;
	V pow(const V &m,ll n,ll mod){
		int k=m.size()-1;
		V r(k),x(k);
		r[0]=x[1]=1;
		while(n){
			if(n&1)r=Vmod(Vmul(x,r,mod),m,mod);
			n>>=1;x=Vmod(Vmul(x,x,mod),m,mod);
		}
		return r;
	}
	ll solve(const V &a,const V &b,ll n,ll mod){
		if(n==0)return 0;
		int k=a.size()-1;
		if(n<=k)return b[n-1];
		if(a.size()==2)return b[0]*quick_pow(a[0],n-1,mod)%mod;
		V r=pow(a,n-1,mod);
		ll ans=0;
		for(int i=0;i<k;i++)ans=(ans+r[i]*b[i]%mod)%mod;
		return (ans+mod)%mod;
	}
	// 返回的式子，删掉首项后调转头尾，即为BM递推式
	V BM(const V &x,ll mod){
		V a{-1},b{-1};
		ll l=0,m=1,c=1;
		for(int n=0;n<x.size();n++){
			//printf("%d %d\n",a.size(),b.size());
			ll d=0;
			for(int i=0;i<l+1;i++)d=(d+a[i]*x[n-i]%mod)%mod;
			if(d==0){
				m++;continue;
			}
			V cur=a;
			ll f=mod-d*get_inv(c,mod)%mod;
			for(int i=a.size();i<b.size()+m;i++)a.push_back(0);
			for(int i=0;i<b.size();i++)a[i+m]=(a[i+m]+f*b[i]%mod)%mod;
			if(2*l>n){
				m++;continue;
			}
			l=n+1-l;b.swap(cur);c=d;m=1;
		}
		reverse(a.begin(),a.end());
		return a;
	}
}

ll solve(V a,ll t,ll l,ll r,ll mod){
	V res=BM::BM(a,mod);
	//printf("--BM-result:--");
	//for(auto i:res)printf("%lld ",i);
	for(int i=0;i<res.size();i++)res[i]=(res[i]+mod)%mod;
	ll ans=(BM::solve(res,a,r/2,mod)-BM::solve(res,a,(l-1)/2,mod)+mod)%mod;
	cout<<BM::solve(res,a,r/2,mod)<<" "<<BM::solve(res,a,(l-1)/2,mod)<<endl;

	ll cnt[10];
	cnt[1]=cnt[2]=cnt[3]=(r/4)%mod;
	if(r%4>=1)cnt[1]++;
	if(r%4>=2)cnt[2]++;
	if(r%4>=3)cnt[3]++;

	cnt[1]-=((l-1)/4)%mod,cnt[2]-=((l-1)/4)%mod,cnt[3]-=((l-1)/4)%mod;
	if((l-1)%4>=1)cnt[1]--;
	if((l-1)%4>=2)cnt[2]--;
	if((l-1)%4>=3)cnt[3]--;
	cnt[1]+=mod,cnt[2]+=mod,cnt[3]+=mod;

	ans=(ans+t*cnt[1]%mod+cnt[2]+t/2*cnt[3]%mod)%mod;
	return ans;
}

int main(){
	ll t,x,y;scanf("%lld%lld%lld",&t,&x,&y);
	V a(5000,0);
	const ll mod=1e9+7;
   	for(int i=1;i<5000;i++){
		a[i-1]=(quick_pow(2*i,t+1,mod)-2*i+mod)%mod;
		a[i-1]=a[i-1]*quick_pow(2*i-1,mod-2,mod)%mod;
		if(i>1)a[i-1]=(a[i-1]+a[i-2])%mod;
	}
	//for(int i=0;i<=100;i++)cout<<a[i]<<" ";

	printf("%lld\n",solve(a,t,x,y,mod));
}