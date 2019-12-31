/**
 * Author: hrynb
 * Time: 2019-09-14 21:06:41
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

int a[110],ans[110];
int main(){
    int n,c=0;sc(n);
    for(int i=1;i<=n;i++)sc(a[i]);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        int doo=0;
        for(int o=1;o<=n;o++)
            if(a[o]%a[i]==0&&!ans[o]){
                if(!doo)doo=1,c++;
                ans[o]=c;
            }
    }
    printf("%d\n",c);
}
