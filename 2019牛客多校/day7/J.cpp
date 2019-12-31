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
		ll a,b;scanf("%lld%lld",&a,&b);
		ll c=0,d=0;
		while(a){
			c=c*10+a%10;
			a/=10;
		}
		while(b){
			d=d*10+b%10;
			b/=10;
		}
		ll ans1=c+d,ans2=0;
		while(ans1){
			ans2=ans2*10+ans1%10;
			ans1/=10;
		}
		printf("%lld\n",ans2);
	}
}
