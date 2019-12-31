/**
 * Author: lzh12139
 * Time: 2019-09-14 21:24:28
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

char s[200010];
int vis[200010];
int main(){
    int t;sc(t);
    while(t--){
        int n,ok=0;sc(n),scs(s+1);
        for(int p=0;p<=9;p++){
            int cnt=0,pre=p,gg=0;
            for(int i=1;i<=n;i++)vis[i]=0;
            for(int i=n;i>=1;i--)
                if(s[i]-'0'<=pre)cnt++,vis[i]=1,pre=s[i]-'0';
                else if(s[i]-'0'<p){gg++;break;}
            if(gg)continue;
            pre=p;
            for(int i=1;i<=n;i++)
                if(s[i]-'0'>=pre&&!vis[i])cnt++,vis[i]=2,pre=s[i]-'0';
                else if(s[i]-'0'>p){gg++;break;}
            if(gg||cnt!=n)continue;

            for(int i=1;i<=n;i++)printf("%d",vis[i]);printf("\n");
            ok++;
            break;
        }
        if(!ok)printf("-\n");
    }
}
