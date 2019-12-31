/**
 * Author: lzh12139
 * Time: 2019-12-15 17:53:31
**/

#include<bits/stdc++.h>
using namespace std;
#define mem(x, y) memset(x, (y), sizeof x)
#define ff first
#define ss second
#define mp(x, y) make_pair(x, y)
#define pb(x) emplace_back(x)
#define sc(a) scanf("%d", &a)
#define scl(a) scanf("%lld", &a)
#define scs(a) scanf("%s", a)
#define pr(a, b) printf("%d%c", a, b)
#define prl(a, b) printf("%ll%c", a, b)
#define all(v) v.begin(), v.end()
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define _yes printf("Yes\n")
#define _no printf("No\n")

typedef long long ll;
typedef vector<int> V;
typedef pair<int, int> pii;
typedef map<int, int> mii;

int main(){
	ll n,k;cin>>n>>k;
	ll ans=1,cur=n,less=0;
	while(ans<k){
		int add=0;
		if(cur&1)cur--,add++;
		else{
			less++;
			cur>>=1;
		}
		if(less==0)add=0;

		ans=(1<<less+1+add)-n+(cur<<less)+add;
		//ans=(1<<less)-(((1<<less)-1)&n)+(1<<less);
		//cout<<cur<<" "<<ans<<endl;
	}
	ll j=n,cnt=0;
	while(j)j>>=1,cnt++;
	for(int i=1;i<cnt;i++){
		ll cal=(1ll<<cnt-i+1)-1;cout<<cal<<endl;
		ll pend=0,ans=cal;
		//while(cal)cal>>=1,pend++;
		if(cal>=k)
			cur=max(cur,(1ll<<i)-1);
	}
	cout<<cur<<endl;
}
