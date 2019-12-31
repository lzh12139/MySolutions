/**
 * Author: hrynb
 * Time: 2019-11-15 14:49:31
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

int main(){
    int t;sc(t);
    while(t--){
        int x,y,cnt=1000;sc(x),sc(y);
        ll cmp=x,ok=0;
        if(cmp>=y)ok=1;
        while(cnt--){
            if(cmp%2==0)cmp=cmp/2*3;
            else cmp--;
            if(cmp>=y){ok=1;break;}
        }
        if(ok)_yes;
        else _no;
    }
}
