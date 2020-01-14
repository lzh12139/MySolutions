/**
 * Author: lzh12139
 * Time: 2020-01-10 22:25:08
**/

#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define mp(x, y) make_pair(x, y)
#define pb(x) emplace_back(x)
#define _yes printf("Yes\n")
#define _no printf("No\n")

typedef long long ll;
typedef vector<int> V;
typedef pair<ll, ll> pii;

int main(){
    ll n;cin>>n;
    pii ans=make_pair(1,n);
    for(ll i=2;i*i<=n;i++)
        if(n%i==0){
            for(ll j=1;j*j<=i;j++)
                if(i%j==0){
                    ll b=n/i*j;
                    if(i/__gcd(i,b)*b==n){
                        if(max(i,b)<max(ans.ff,ans.ss))ans=make_pair(i,b);
                    }

                    b=n/j;
                    if(i/__gcd(i,b)*b==n){
                        if(max(i,b)<max(ans.ff,ans.ss))ans=make_pair(i,b);
                    }
                }
        }
    cout<<ans.ff<<" "<<ans.ss;
}