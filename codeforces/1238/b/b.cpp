/**
 * Author: lzh12139
 * Time: 2019-10-08 22:41:18
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

int a[100010],n,r;
int main(){
    int t;sc(t);
    while(t--){
        sc(n),sc(r);
        for(int i=1;i<=n;i++)sc(a[i]);
        sort(a+1,a+1+n);
        n=unique(a+1,a+1+n)-a-1;
        for(int i=1;i<=n;i++)
            if(a[n-i]<=1ll*i*r){
                pr(i,'\n');break;
            }
    }
}
