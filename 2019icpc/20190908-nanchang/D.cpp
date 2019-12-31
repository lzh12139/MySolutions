#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=100003;
const ll phimod=mod-1;

ll quickmod(ll base,ll x){
	ll res=1;
	while(x){
		if(x&1)res=res*base%mod;
		base=base*base%mod;
		x>>=1;
	}
	return res%mod;
}
const int N=140000;
const long double PI=acos(-1.0);

struct cpx {
	long double x,y;
	cpx() {}
	cpx(long double _x,long double _y):x(_x),y(_y) {}
	cpx operator+(const cpx &b)const{
		return cpx(x+b.x,y+b.y);
	}
	cpx operator-(const cpx &b)const{
		return cpx(x-b.x,y-b.y);
	}
	cpx operator*(const cpx &b)const{
		return cpx(x*b.x-y*b.y,x*b.y+y*b.x);
	}
	cpx operator/(const int &b)const{
		return cpx(x/b,y/b);
	}
};

int rev[2*N+10];

void fft(cpx x[],int len,int inv){
	int bit=0;
	while((1<<bit)<len-1)bit++;
	for(int i=0;i<len;i++){
		rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
		if(i<rev[i])swap(x[i+1],x[rev[i]+1]);
	}
	for(int mid=1;mid<len;mid<<=1){
		cpx tmp(cos(PI/mid),inv*sin(PI/mid));
		for(int i=1;i<=len;i+=mid*2){
			cpx base(1,0);
			for(int j=i;j<i+mid;j++,base=base*tmp){
				cpx a=x[j],b=base*x[j+mid];
				x[j]=a+b,x[j+mid]=a-b;
			}
		}
	}

	if(inv==-1)
		for(int i=1;i<=len;i++)x[i]=x[i]/len;
}

cpx ffta[2*N+10],fftb[2*N+10];
int solve(ll a[],ll b[],int lena,int lenb){
	int len=1;
	while(len<lena+lenb)len<<=1;

	for(int i=1;i<=lena;i++)ffta[i]=cpx(a[i],0);
	for(int i=lena+1;i<=len;i++)ffta[i]=cpx(0,0);
	for(int i=1;i<=lenb;i++)fftb[i]=cpx(b[i],0);
	for(int i=lenb+1;i<=len;i++)fftb[i]=cpx(0,0);

	fft(ffta,len,1),fft(fftb,len,1);
	for(int i=1;i<=len;i++)ffta[i]=ffta[i]*fftb[i];
	fft(ffta,len,-1);
	return len;
}
ll s[N+10],C[N+10],mul[N+10],a[N+10],b[N+10];
void ac(int l,int r){
	if(l==r)return;
	/*if(l+1==r){
		ll a1=s[l],a2=s[r];
		s[l]=a1*a2%mod,s[r]=(a1+a2)%mod;
		return;
	}*/
	int mid=l+r>>1;
	//for(int i=l;i<=r;i++)printf("%d ",s[i]);printf("\n");
	ac(l,mid),ac(mid+1,r);
	int cnta=0,cntb=0;
	for(int i=l;i<=mid;i++)a[++cnta]=s[i]%mod;
	a[++cnta]=1;
	for(int i=mid+1;i<=r;i++)b[++cntb]=s[i]%mod;
	b[++cntb]=1;
	solve(a,b,cnta,cntb);
	//for(int i=1;i<=len;i++)printf("%d ",int(ffta[i].x+0.5));printf("\n");
	for(int i=l,j=1;i<=r;i++,j++){
		ll val=floor(ffta[j].x+0.5);
		s[i]=val%mod;
	}
}
ll revv[N+10];
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out1.txt","w",stdout);
	ll n,a,q;scanf("%lld%lld%lld",&n,&a,&q);

	mul[0]=1;
	for(int i=1;i<=n;i++)mul[i]=mul[i-1]*i%mod;
	revv[n]=quickmod(mul[n],mod-2);
	for(int i=n-1;i>=1;i--)revv[i]=revv[i+1]*(i+1)%mod;
	for(int i=1;i<=n;i++){
		//ll u=mul[n],d=mul[n-i]*mul[i]%mod;
		C[i]=mul[n]*quickmod(mul[n-i],mod-2)%mod*quickmod(mul[i],mod-2)%mod;
		//C[i]=mul[n]*revv[i]%mod*revv[n-i]%mod;
		//printf("%lld\n",C[i]);
		//printf("%d %d %d %d\n",u,d,C[i],quickmod(d,mod-2));
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&s[i]);
		s[i]=quickmod(a,s[i]%phimod)%mod;
	}
	ac(1,n);
	//for(int i=1;i<=10;i++)printf("%d ",s[i]);
	ll inv=quickmod(a-1,mod-2)%mod;
	while(q--){
		int x;scanf("%d",&x);
		printf("%lld\n",(s[n-x+1]-C[x]+mod)%mod*inv%mod);
	}
}