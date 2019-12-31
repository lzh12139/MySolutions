/**
 * Author: lzh12139
 * Time: 2019-10-16 22:37:38
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
    int c=0;
    int n;sc(n);
    for(int i=1;i<=n;i++){
        int x;sc(x);
        if(abs(x)&1){
            if(c){
                c=0;
                if(x<0)x=x/2;
                else x=x/2+1;
            }
            else {
                c=1;
                if(x>0)x=x/2;
                else x=x/2-1;
            }
        }
        else x=x/2;
        printf("%d\n",x);
    }
}
