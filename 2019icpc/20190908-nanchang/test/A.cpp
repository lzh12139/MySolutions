#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ff first
#define ss second
#define mp make_pair
const int N=5000000;
int prime[N+10],phi[N+10];
unordered_map<int,ll>mapphi;
struct node{
	ll val;
	int ans;
	node(){}
	node(ll _v,int _a):val(_v),ans(_a){}
	bool operator<(const node &b)const{
		return val<b.val;
	}
};
const int S=500;
vector<node>v[N/S+10];
void sieve(){
	prime[0]=0,phi[1]=1;
	for(int i=2;i<=N;i++){
		if(!prime[i])prime[++prime[0]]=i,phi[i]=i-1;
		for(int o=1;o<=prime[0]&&prime[o]<=N/i;o++){
			prime[i*prime[o]]++;
			if(i%prime[o]==0){
				phi[i*prime[o]]=phi[i]*prime[o];
				break;
			}
			phi[i*prime[o]]=phi[i]*phi[prime[o]];
		}
	}
	//printf("%d\n",cnt);
	for(int i=1;i<=N-2;i++)v[(phi[i]-1)/S].emplace_back(node(1ll*phi[i+1]*N+phi[i+2],i));
	for(int i=0;i<=N/S;i++)sort(v[i].begin(),v[i].end());
	//for(int i=1;i<=N-2;i++)mapnode[mp(phi[i],1ll*phi[i+1]*N+phi[i+2])]=i;
}
inline int phii(int x){
	if(x<=N)return phi[x];
	if(mapphi[x])return mapphi[x];
	int inf=sqrt(x+0.5);
	int ans=x,pre=x;
	for(int i=2;i<=inf&&x>=i;i++)
		if(x%i==0){
			ans=ans/i*(i-1);
			while(x%i==0)x/=i;
		}
	if(x>1)ans=ans/x*(x-1);
	//printf("%d %d\n",pre,ans);
	return mapphi[pre]=ans;
}
int a[110];
int check(int pos){
	if(pos<=0||pos+99>150000000)return 0;
	for(int i=pos,j=1;j<=100;i++,j++)if(a[j]!=phii(i)){return 0;}
	return 1;
}
int main(){
	sieve();
	int t=1;scanf("%d",&t);
	//int st=140000000;
	//for(int i=st,j=1;j<=100;i++,j++)a[j]=phii(i),printf("%d ",phii(i));printf("\n");
	while(t--){
		for(int i=1;i<=100;i++)scanf("%d",&a[i]);
		int ans=-1;
		for(int i=1;i<36;i++){
			if(a[i]%16==0&&a[i+32]%32==0&&a[i+64]%16==0){
				//printf("a:i=%d\n",i);
				int x1=a[i]/16,x2=a[i+32]/32,x3=a[i+64]/16;
				int xx1=(x1-1)/S;
				auto x=lower_bound(v[xx1].begin(),v[xx1].end(),node(1ll*x2*N+x3,0));
				//printf("check:%d %d\n",i,x->ans);
				if(x!=v[xx1].end()&&x->val==1ll*x2*N+x3&&check(x->ans*32-i+1)){
					ans=x->ans*32-i+1;break;
				}
				//int x=mapnode[mp(a[i]/16,1ll*a[i+32]/32*N+a[i+64]/16)];
				//printf("%d %d\n",i,x);
				//if(x!=0&&check(x)){ans=x;break;}
			}
			if(a[i]%32==0&&a[i+32]%16==0&&a[i+64]%32==0){
				//printf("b:i=%d\n",i);
				int x1=a[i]/32,x2=a[i+32]/16,x3=a[i+64]/32;
				int xx1=(x1-1)/S;
				auto x=lower_bound(v[xx1].begin(),v[xx1].end(),node(1ll*x2*N+x3,0));
				//printf("check:%d %d\n",i,x->ans);
				if(x!=v[xx1].end()&&x->val==1ll*x2*N+x3&&check(x->ans*32-i+1)){
					ans=x->ans*32-i+1;break;
				}
				//int x=mapnode[mp(a[i]/32,1ll*a[i+32]/16*N+a[i+64]/32)];
				//printf("%d %d\n",i,x);
				//if(x!=0&&check(x)){ans=x;break;}
			}
		}
		if(ans==-1)printf("NO\n");
		else printf("YES\n%d\n",ans);
	}
}
/*
1 1 2 2 4 2 6 4 6 4 10 4 12 6 8 8 16 6 18 8 12 10 22 8 20 12 18 12 28 8 30 16
20 16 24 12 36 18 24 16 40 12 42 20 24 22 46 16 42 20 32 24 52 18 40 24 36 28 58 16 60 30 36 32 
48 20 66 32 44 24 70 24 72 36 40 36 60 24 78 32 54 40 82 24 64 42 56 40 88 24 72 44 60 46 72 32 
96 42 60 40
*/