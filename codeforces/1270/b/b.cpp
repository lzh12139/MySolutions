/**
 * Author: hrynb
 * Time: 2020-01-07 14:12:34
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
#define _yes printf("YES\n")
#define _no printf("NO\n")

typedef long long ll;
typedef vector<int> V;
typedef pair<int, int> pii;
typedef map<int, int> mii;

int a[200010];
int main(){
    int t;scanf("%d",&t);
    while(t--){
        int n;scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",a+i);
        int ok=0;
        for(int i=2;i<=n;i++)
            if(abs(a[i]-a[i-1])>=2){
                _yes;
                printf("%d %d\n",i-1,i);
                ok=1;
                break;
            }
        if(!ok)_no;
    }
}
