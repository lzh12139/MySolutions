/**
 * Author: lzh12139
 * Time: 2019-10-17 22:09:30
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

int a[510][510];
int main(){
    int n;sc(n);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)sc(a[i][j]);
    int ans=1e9;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    if(i!=j){
            int tmp=0;
        for(int k=1;k<=n;k++)
        for(int l=1;l<=n;l++)
        if(a[i][k]>=a[j][l])tmp++;
        ans=min(ans,tmp);
    }
    cout<<ans;
}
