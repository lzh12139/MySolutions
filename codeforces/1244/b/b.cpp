/**
 * Author: lzh12139
 * Time: 2019-10-13 17:11:44
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

char s[1010];
int main(){
    int t;sc(t);
    while(t--){
        int n;sc(n),scs(s+1);
        int ans=n,tmp=0;
        for(int i=1;i<=n;i++)if(s[i]=='1')ans++;
        for(int i=1;i<=n;i++)if(s[i]=='1'){tmp=max(tmp,2*(n-i+1));break;}
        for(int i=n;i>=1;i--)if(s[i]=='1'){tmp=max(tmp,2*i);break;}
        printf("%d\n",max(tmp,ans));
    }
}
