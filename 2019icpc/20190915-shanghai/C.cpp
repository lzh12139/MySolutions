#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=560000;
const double PI=acos(-1.0);

struct cpx {
	double x,y;
	cpx() {}
	cpx(double _x,double _y):x(_x),y(_y) {}
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
void getrev(int len){
	int bit=0;
	while((1<<bit)<len-1)bit++;
	for(int i=0;i<len;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
}

void fft(cpx x[],int len,int inv){
	for(int i=0;i<len;i++)
		if(i<rev[i])swap(x[i+1],x[rev[i]+1]);
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
int solve(int a[],int b[],int lena,int lenb){
	int len=1;
	while(len<lena+lenb)len<<=1;
	getrev(len);

	for(int i=1;i<=lena;i++)ffta[i]=cpx(a[i],0);
	for(int i=lena+1;i<=len;i++)ffta[i]=cpx(0,0);
	for(int i=1;i<=lenb;i++)fftb[i]=cpx(b[i],0);
	for(int i=lenb+1;i<=len;i++)fftb[i]=cpx(0,0);

	fft(ffta,len,1),fft(fftb,len,1);
	for(int i=1;i<=len;i++)ffta[i]=ffta[i]*fftb[i];
	fft(ffta,len,-1);
	return len;
}

int a[N+10],b[N+10],c[N+10];
int cnta[2*N+10],cntb[2*N+10],cntc[2*N+10];
ll ab[2*N+10],ac[2*N+10],bc[2*N+10];

typedef pair<int,int> pii;
pii p[N+10];
#define mp make_pair
#define ff first
#define ss second

int main(){
	int t,kase=1;scanf("%d",&t);
	while(t--){
		int n,maxa=0,maxb=0,maxc=0;scanf("%d",&n);
		if(n>1000){
			for(int i=1;i<=n;i++)scanf("%d",&a[i]),maxa=max(maxa,a[i]),cnta[a[i]]++;
            for(int i=1;i<=n;i++)scanf("%d",&b[i]),maxb=max(maxb,b[i]),cntb[b[i]]++;
            for(int i=1;i<=n;i++)scanf("%d",&c[i]),maxc=max(maxc,c[i]),cntc[c[i]]++;

            int ablen=solve(cnta,cntb,maxa,maxb);
            for(int i=1;i<=ablen;i++)ab[i+1]=(ll)(ffta[i].x+0.5);
            for(int i=ablen-1;i>=1;i--)ab[i]+=ab[i+1];

            int bclen=solve(cntb,cntc,maxb,maxc);
			for(int i=1;i<=bclen;i++)bc[i+1]=(ll)(ffta[i].x+0.5);
			for(int i=bclen-1;i>=1;i--)bc[i]+=bc[i+1];

			int aclen=solve(cnta,cntc,maxa,maxc);
			for(int i=1;i<=aclen;i++)ac[i+1]=(ll)(ffta[i].x+0.5);
			for(int i=aclen-1;i>=1;i--)ac[i]+=ac[i+1];

			for(int i=1;i<=n;i++)p[3*i-2]=mp(a[i],1),p[3*i-1]=mp(b[i],2),p[3*i]=mp(c[i],3);

			sort(p+1,p+1+3*n,greater<pii>());
			ll numa=0,numb=0,numc=0,inf=1ll*n*n,ans=0;
			/*for(int i=1;i<=3*n;i++)
				if(p[i].ff==1)ans+=bc[p[i].ff];
				else if(p[i].ss)*/
			for(int i=1;i<=3*n;i++){
				//printf("%lld %d %d\n",ans,p[i].ff,p[i].ss);
				if(p[i].ss==1){
					ans+=bc[p[i].ff];
					ans-=inf-(n-numb)*(n-numc);
					numa++;
				}
				else if(p[i].ss==2){
					ans+=ac[p[i].ff];
					ans-=inf-(n-numa)*(n-numc);
					numb++;
				}
				else {
					ans+=ab[p[i].ff];
					ans-=inf-(n-numa)*(n-numb);
					numc++;
				}
			}
			
			for(int i=1;i<=n;i++)cnta[a[i]]=cntb[b[i]]=cntc[c[i]]=0;
			for(int i=1;i<=ablen;i++)ab[i]=0;
			for(int i=1;i<=bclen;i++)bc[i]=0;
			for(int i=1;i<=aclen;i++)ac[i]=0;

            printf("Case #%d: %lld\n",kase++,ans);
		}
		else{
			for(int i=1;i<=n;i++)scanf("%d",&a[i]);
			for(int i=1;i<=n;i++)scanf("%d",&b[i]);
			for(int i=1;i<=n;i++)scanf("%d",&c[i]);
			sort(b+1,b+1+n);
			sort(c+1,c+1+n);
			ll ans=0;

			for(int i=1;i<=n;i++){
				int al=n,ar=1,bl=1,br=1;
				for(int o=1;o<=n;o++)
					if(b[o]<=a[i]){
						int less=a[i]-b[o],add=a[i]+b[o];
						while(al>=1&&less<=c[al])al--;
						while(ar<=n&&add>=c[ar])ar++;
						//printf("a: %d %d %d %d %d\n",i,o,al,ar,ar-al-1);
						ans+=ar-al-1;
					}
					else{
						int less=b[o]-a[i],add=a[i]+b[o];
						while(bl<=n&&less>c[bl])bl++;
						while(br<=n&&add>=c[br])br++;
						ans+=br-bl;
						//printf("b: %d %d %d %d %d\n",i,o,bl,br,br-bl-1);
					}
			}
			printf("Case #%d: %lld\n",kase++,ans);
		}
	}
}