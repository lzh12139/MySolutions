/**
 * Author: hrynb
 * Time: 2019-10-09 10:55:30
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

char a[110],b[110];
int num[30];
int main(){
    int t;sc(t);
    while(t--){
        scs(a+1),scs(b+1);
        int n=strlen(a+1);
        for(int i=1;i<=26;i++)num[i]=0;
        for(int i=1;i<=n;i++)num[a[i]-'a'+1]=1;
        int ok=0;
        for(int i=1;i<=n;i++)if(num[b[i]-'a'+1]){ok=1;break;}
        if(ok)_yes;
        else _no;
    }
}
