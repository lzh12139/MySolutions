/**
 * Author: hrynb
 * Time: 2019-11-15 15:00:26
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

int pre[200010];
int main(){
    int t;sc(t);
    while(t--){
        int n,ans=1e9;sc(n);
        for(int i=1;i<=n;i++)pre[i]=0;
        for(int i=1;i<=n;i++){
            int x;sc(x);
            if(pre[x])ans=min(ans,i-pre[x]);
            pre[x]=i;
        }
        if(ans==1e9)printf("-1\n");
        else pr(ans+1,'\n');
    }
}
