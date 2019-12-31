/**
 * Author: lzh12139
 * Time: 2019-10-17 22:01:07
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

int a[500][500];
int main(){
    int n;sc(n);
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(i&1)for(int j=1;j<=n;j++)a[i][j]=++cnt;
        else for(int j=n;j>=1;j--)a[i][j]=++cnt;
    }
    for(int j=1;j<=n;j++)
        for(int i=1;i<=n;i++)printf("%d%c",a[i][j]," \n"[i==n]);
}
