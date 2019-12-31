/**
 * Author: lzh12139
 * Time: 2019-10-17 21:55:55
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
    int t;sc(t);
    while(t--){
        int a,b,c;sc(a),sc(b),sc(c);
        int aa=a,bb=b,cc=c;
        int ans1=0,ans2=0;
        while(b>=1&&c>=2)b-=1,c-=2,ans1++;
        while(a>=1&&b>=2)a--,b-=2,ans1++;

        while(aa>=1&&bb>=2)aa--,bb-=2,ans2++;
        while(bb>=1&&cc>=2)bb--,cc-=2,ans2++;
        printf("%d\n",max(ans1,ans2)*3);
    }
}
