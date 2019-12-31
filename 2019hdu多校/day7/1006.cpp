#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define ff first
#define ss second
#define ll long long
#define mp make_pair
#define pb emplace_back

int main(){
	int t;scanf("%d",&t);
	while(t--){
		int n,m,k;scanf("%d%d%d",&n,&m,&k);
		ll ans;
		if(n>=m+k)ans=k;
		else ans=1ll*n*(1+m/(n-k+1));
		printf("%lld\n",ans);
	}
}
