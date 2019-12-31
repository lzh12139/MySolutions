#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define mp make_pair
#define ll long long
#define up(i,a,b) for(int i=(a);i<=(b);i++)
#define down(i,a,b) for(int i=(a);i>=(b);i--)
#define pb emplace_back
typedef pair<int,int> pii;

ll ans[100020];
ll mod=998244353;
void pre() {
	ans[1]=0;
	ans[2]=ans[3]=ans[4]=1;
	up(i,5,100012)ans[i]=(ans[i-1]+ans[i-3])%mod;
}
int main() {
	pre();
	int t;
	scanf("%d",&t);
	while(t--) {
		int n,x,y;
		ll ansn;
		scanf("%d%d%d",&n,&x,&y);
		if(x==1) {
			if(y==n)ansn=ans[n+1];
			else ansn=ans[y];
		} else {
			if(y==n)ansn=ans[n-x+1];
			else ansn=ans[y-x];
		}
		printf("%lld\n",ansn);
	}
}
