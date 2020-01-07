/**
 * Author: hrynb
 * Time: 2020-01-07 14:23:09
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
    int t;scanf("%d",&t);
    while(t--){
        int n;scanf("%d",&n);
        ll sum=0,r=0;
        for(int i=1;i<=n;i++){
            int x;scanf("%d",&x);
            sum+=x,r^=x;
        }
        r<<=1;

        vector<ll>ans;
        ans.clear();
        if(sum&1){
            ans.push_back(1);
            sum++,r^=2;
        }
        if(sum<r)ans.push_back(r-sum>>1),ans.push_back(r-sum>>1);
        if(sum>r)ans.push_back(r/2),ans.push_back(sum+r/2);

        printf("%d\n",ans.size());
        for(auto i:ans)printf("%lld ",i);
        printf("\n");
    }
}
