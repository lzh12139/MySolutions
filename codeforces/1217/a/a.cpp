/**
 * Author: lzh12139
 * Time: 2019-09-05 22:36:39
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
typedef unsigned long long ull;
typedef vector<int> V;
typedef pair<int, int> pii;
typedef map<int, int> mii;
typedef map<string, int> msi;

int main(){
    int t;sc(t);
    while(t--){
        int a,b,c;sc(a),sc(b),sc(c);
        if(c==0){
            if(a>b)pr(1,'\n');
            else pr(0,'\n');
        }
        else{
            int ans=min(max((a+c-b+1)/2,0),c+1);
            pr(ans,'\n');
        }
    }
}
