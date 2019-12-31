/**
 * Author: lzh12139
 * Time: 2019-12-15 17:24:25
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

char s[500];
int a[500],ans[700];
int main(){
    int n,b=0;cin>>n>>s+1;
    for(int i=1;i<=n;i++)
        if(s[i]=='B')a[i]=1,b++;
    if((b&1)&&(n-b&1))puts("-1");
    else{
        if(!(b&1)){
            int pre=-1;
            for(int i=1;i<=n;i++)
                if(a[i]){
                    if(pre==-1)pre=i;
                    else {
                        for(int j=pre;j<i;j++)
                            ans[++ans[0]]=j;
                        pre=-1;
                    }
                }
        }
        else{
            int pre=-1;
            for(int i=1;i<=n;i++)
                if(!a[i]){
                    if(pre==-1)pre=i;
                    else {
                        for(int j=pre;j<i;j++)
                            ans[++ans[0]]=j;
                        pre=-1;
                    }
                }
        }
        cout<<ans[0]<<"\n";
        for(int i=1;i<=ans[0];i++)cout<<ans[i]<<" ";
    }
}
