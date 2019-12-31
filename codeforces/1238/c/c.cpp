/**
 * Author: lzh12139
 * Time: 2019-10-08 22:58:04
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

int a[400010];
int main(){
    int t;sc(t);
    while(t--){
        int h,n;sc(h),sc(n);
        for(int i=1;i<=n;i++)sc(a[i]);
        if(n==1){
            pr(0,'\n');continue;
        }
        a[n+1]=0;
        int cur=h,ans=0;
        for(int i=1;i<=n&&cur>2;i++){
            if(cur==a[i]+1){
                if(a[i+1]+1==a[i]){
                    if(i==n){
                        if(cur>2)ans++;
                    }
                    else cur=a[i+2]+1,i++;
                }
                else{
                    cur=a[i+1]+1,ans++;
                }
            }
            else{
                cur=a[i+1]+1;
            }
            //printf("--%d %d\n",ans,cur);
        }
        pr(ans,'\n');
    }
}
