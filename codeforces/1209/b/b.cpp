/**
 * Author: lzh12139
 * Time: 2019-09-14 21:11:11
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

char s[110];
int a[110],b[110],sum[1100000];
int main(){
    int n;sc(n),scs(s+1);
    for(int i=1;i<=n;i++)sc(a[i]),sc(b[i]);
    for(int o=1;o<=n;o++){
        int st,base=a[o]*2;
        if(s[o]=='1')sum[1]++,sum[b[o]+1]--,st=b[o]+a[o]+1;
        else st=b[o]+1;

        for(int i=0;i<=100000;i++)sum[st+base*i]++,sum[st+base*i+a[o]]--;
    }
    int ans=0;
    for(int i=1;i<=1001000;i++)sum[i]+=sum[i-1],ans=max(ans,sum[i]);
    //for(int i=1;i<=10;i++)printf("%d ",sum[i]);
    printf("%d\n",ans);
}
