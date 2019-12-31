/**
 * Author: lzh12139
 * Time: 2019-12-15 17:33:44
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
    int n;sc(n);
    pii s;sc(s.ff),sc(s.ss);
    int a=0,b=0,c=0,d=0;
    for(int i=1;i<=n;i++){
        int x,y;sc(x),sc(y);
        if(x<=s.ff-1)a++;
        if(x>=s.ff+1)b++;
        if(y<=s.ss-1)c++;
        if(y>=s.ss+1)d++;
    }
    int maxx=max(max(a,b),max(c,d));
    printf("%d\n",maxx);
    if(maxx==a){
        printf("%d %d\n",s.ff-1,s.ss);return 0;
    }
    if(maxx==b){
        printf("%d %d\n",s.ff+1,s.ss);return 0;
    }
    if(maxx==c){
        printf("%d %d\n",s.ff,s.ss-1);return 0;
    }
    if(maxx==d){
        printf("%d %d\n",s.ff,s.ss+1);return 0;
    }
}
