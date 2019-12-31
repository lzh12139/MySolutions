/**
 * Author: lzh12139
 * Time: 2019-09-05 22:54:29
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
int a[200010];
int main(){
    int t;sc(t);
    while(t--){
        scs(s+1);
        int n=strlen(s+1);
        ll ans=0;
        for(int i=1;i<=n;i++)if(s[i]=='1')ans++;
        for(int i=2;i<=n;i++)if(s[i-1]=='1'&&s[i]=='0')ans++;
        //printf("%lld\n",ans);
        for(int i=1;i<=n;i++)
            if(s[i]=='0'){
                int to=i;
                while(s[to]=='0'&&to<=n)to++;
                int len=to-i;
                a[0]=0;
                for(int o=to;o<=n;o++){
                    int x=a[a[0]]*2+s[o]-'0';
                    if(x>n)break;
                    a[++a[0]]=x;
                }
                for(int o=1;o<=a[0];o++)if(o<=a[o]&&a[o]<=o+len&&(a[o]>2))ans++;

                //printf("%d %d %lld\n",i,to-1,ans);

                i=to-1;
            }
        printf("%lld\n",ans);
    }
}
