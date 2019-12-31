/**
 * Author: hrynb
 * Time: 2019-11-27 21:56:21
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
        int a,b;sc(a),sc(b);
        if((a+b)%3){_no;continue;}
        int plus=(a+b)/3,sub=b-a;
        if((plus+sub)%2||(plus-sub)%2){_no;continue;}
        int x=(plus+sub)/2,y=(plus-sub)/2;
        if(x>=0&&y>=0)_yes;
        else _no;
    }
}
