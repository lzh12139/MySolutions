/**
 * Author: hrynb
 * Time: 2019-11-27 22:06:18
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

ll exgcd(ll a,ll b,ll &x,ll &y){
	if(b==0){
		x=1;
		y=0;
		return a;//gcd(a,b)
	}
	ll gcd_ab=exgcd(b,a%b,x,y);
	ll temp=x;
	x=y;
	y=temp-a/b*y;
	return gcd_ab;
}

int main(){
	int t;sc(t);
	while(t--){
		ll a,b,k;scl(a),scl(b),scl(k);
		if(a>b)swap(a,b);
/*
		if(k==1){
			puts("REBEL");continue;
		}
*/
		if(a==b){
			puts("OBEY");continue;
		}

		ll g=__gcd(a,b);
		//if(g==a)g=0;
		if(b-1ll*(k-1)*a-g>0)puts("REBEL");
		else puts("OBEY");
/*
		if(1ll*a*k<b){
			puts("REBEL");continue;
		}
		else if(1ll*a*k==b){
			puts("OBEY");continue;
		}
		puts("OBEY");*/
	}
}
