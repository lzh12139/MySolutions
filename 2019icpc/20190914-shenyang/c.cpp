#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define ff first
#define ss second
#define mp make_pair
#define pb emplace_back
pii p[1010];
ll dp[20010];
int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		for(int i=1;i<=n;i++){
			scanf("%d%d",&p[i].ff,&p[i].ss);
		}
		for(int i=1;i<=20000;i++)dp[i]=1e18;
		for(int i=1;i<=n;i++){
			dp[p[i].ss]=min(dp[p[i].ss],1ll*p[i].ff);
			for(int o=1;o<m;o++)
			if(dp[o]!=1e18)dp[o+p[i].ss]=min(dp[o+p[i].ss],dp[o]+p[i].ff);
			//printf("dp %d: ",i);
			//for(int o=1;o<=2*m;o++)printf("%lld ",dp[o]);printf("\n");
		}
		ll ansp=1e18+2,ansc=1e18+2;
		for(int i=m;i<=20000;i++)if(ansp>=dp[i])ansp=dp[i],ansc=i;
		printf("%lld %lld\n",ansp,ansc);
	}
}