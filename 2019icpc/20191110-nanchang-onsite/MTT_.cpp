#include<cstdio>
#include<algorithm>
#include<vector>
#define SF scanf
#define PF printf
#define MAXN 300010
#define MOD 1000000007
using namespace std;
typedef long long ll;
const int G=3;
ll g[MAXN],B[MAXN],ifac[MAXN],fac[MAXN];
ll fsa(ll x,ll y,ll mod){
//	x%=mod,y%=mod;
//	ll res=0;
//	while(y){
//		if(y&1ll)
//			res=(res+x)%mod;	
//		x=(x+x)%mod;
//		y>>=1ll;
//	}
//	return res;
	return (x*y-(ll)((long double)x/mod*y)*mod+mod)%mod;
}
ll fsp(ll x,ll y,ll mod){
	x%=mod;
	ll res=1;
	while(y){
		if(y&1ll)
			res=res*x%mod;
		x=x*x%mod;
		y>>=1ll;
	}
	return res;
}
void NTT(ll A[],int N,int flag,ll mod){
	for(int i=1,j=0;i<N;i++){
		for(int d=N;j^=d>>=1,~j&d;);
		if(i<j)
			swap(A[i],A[j]);
	}
	for(int i=1;i<N;i<<=1){
		ll wn=fsp(G,(mod-1)/(i<<1),mod);
		if(flag)
			wn=fsp(wn,mod-2,mod);
		for(int j=0;j<N;j+=(i<<1)){
			ll w=1;
			for(int k=0;k<i;k++,w=w*wn%mod){
				ll x=A[j+k],y=A[i+j+k]*w%mod;
				A[j+k]=(x+y)%mod;
				A[i+j+k]=(x-y+mod)%mod;
			}
		}
	}
	if(flag){
		ll invN=fsp(N,mod-2,mod);
		for(int i=0;i<N;i++)
			A[i]=A[i]*invN%mod;
	}
}
void Mul(ll A[],ll B[],int N,int M,ll res[],ll mod){
	static ll tmp1[MAXN],tmp2[MAXN];
	for(int i=0;i<N;i++)
		tmp1[i]=A[i];
	for(int i=0;i<M;i++)
		tmp2[i]=B[i];
	int p=1;
	while(p<=N+M)
		p<<=1;
	NTT(tmp1,p,0,mod);
	NTT(tmp2,p,0,mod);
	for(int i=0;i<p;i++)
		res[i]=tmp1[i]*tmp2[i]%mod;
	NTT(res,p,1,mod);
	for(int i=0;i<p;i++)
		tmp1[i]=tmp2[i]=0;
}
ll Mod[3]={998244353,469762049,1004535809};
void MTT(ll A[],ll B[],int N,int M,ll res[]){
	static ll res1[MAXN],res2[MAXN],res3[MAXN];
	Mul(A,B,N,M,res1,Mod[0]);
	Mul(A,B,N,M,res2,Mod[1]);
	Mul(A,B,N,M,res3,Mod[2]);
	ll M1=Mod[0]*Mod[1];
	ll IM0=fsp(Mod[0],Mod[1]-2,Mod[1]);
	ll IM1=fsp(Mod[1],Mod[0]-2,Mod[0]);
	for(int i=0;i<N+M;i++){
		ll c=(fsa(res1[i]*Mod[1],IM1,M1)+
            fsa(res2[i]*Mod[0],IM0,M1))%M1;
		ll x=((res3[i]-c)%Mod[2]+Mod[2])%Mod[2]*fsp(M1,Mod[2]-2,Mod[2])%Mod[2];
		res[i]=(x*(M1%MOD)%MOD+c)%MOD;
	}
	for(int i=0;i<N+M;i++)
		res1[i]=res2[i]=res3[i]=0;
}
void Inv(ll A[],ll B[],int N){
	if(N==1){
		B[0]=fsp(A[0],MOD-2,MOD);
		return ;
	}
	Inv(A,B,(N+1)>>1);
	static ll tmp1[MAXN],tmp2[MAXN];
	MTT(A,B,N,N,tmp1),MTT(B,tmp1,N,N,tmp2);
//	if(N==8){
//		for(int i=0;i<N;i++)
//			PF("[%lld]",B[i]);
//		PF("\n");
//		for(int i=0;i<N;i++)
//			PF("[%lld]",tmp1[i]);
//		PF("\n");
//		for(int i=0;i<N;i++)
//			PF("[%lld]",tmp2[i]);
//		PF("\n");	
//	}
	for(int i=0;i<N;i++) B[i]=(B[i]*2ll-tmp2[i]+MOD)%MOD;
	for(int i=0;i<2*N;i++) tmp1[i]=tmp2[i]=0;
}
ll C(int n,int m){
	return fac[n]*ifac[m]%MOD*ifac[n-m]%MOD;	
}
int main(){
	int n=65536;
	fac[0]=1;
	for(int i=1;i<=n*2;i++)
		fac[i]=fac[i-1]*i%MOD;
	ifac[n*2]=fsp(fac[n*2],MOD-2,MOD);
	for(int i=n*2;i>=1;i--)
		ifac[i-1]=ifac[i]*i%MOD;
	for(int i=0;i<n;i++)
		g[i]=ifac[i+1];
//	for(int i=0;i<8;i++)
//		PF("%lld ",g[i]);
	Inv(g,B,n);
	for(int i=0;i<n;i++)
		B[i]=B[i]*fac[i]%MOD;
//	for(int i=0;i<8;i++)
//		PF("%lld ",B[i]);
	int T,k;
	ll N;
	SF("%d",&T);
	while(T--){
		SF("%lld%d",&N,&k);	
		ll ans=0;
		ll nw=(N+1)%MOD,q=(N+1)%MOD;
		for(int i=k;i>=0;i--,nw=nw*q%MOD)
			ans=(ans+C(k+1,i)*B[i]%MOD*nw%MOD)%MOD;
		ans=ans*fsp(k+1,MOD-2,MOD)%MOD;
		PF("%lld\n",ans);
	}
}
