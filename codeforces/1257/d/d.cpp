/**
 * Author: hrynb
 * Time: 2019-11-15 15:47:13
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

int a[200010],nex[200010];
int maxx[200010];

int d[20][200010];
int query(int l,int r){
    int t=log2(r-l+1);
    return max(d[t][l],d[t][r-(1<<t)+1]);
}
void init(int a[],int len){
    for (int i=1;i<=len;++i){
        d[0][i]=a[i];
    }
    int t=1;
    for (int i=1;t<=len;++i){
        for (int j=1;j+t<=len;++j)
            d[i][j]=max(d[i-1][j],d[i-1][j+t]);
        t<<=1;
    }
}

int main(){
    int t;sc(t);
    while(t--){
        int n;sc(n);
        for(int i=1;i<=n;i++)sc(a[i]),maxx[i]=0;
        int m;sc(m);
        for(int i=1;i<=m;i++){
            int x,y;sc(x),sc(y);
            maxx[y]=max(maxx[y],x);
        }
        for(int i=n-1;i>=1;i--)maxx[i]=max(maxx[i+1],maxx[i]);

        init(a,n);
        
        int gg=0;
        for(int i=1;i<=n;i++){
            int l=1,r=n-i+1,tmp=-1;
            while(l<=r){
                int mid=l+r>>1;
                if(query(i,i+mid-1)<=maxx[mid])
                    l=mid+1,tmp=max(tmp,mid);
                else r=mid-1;
            }
            if(tmp==-1){gg=1;break;}
            nex[i]=tmp;
        }

        if(gg){printf("-1\n");continue;}
        int ans=0,pre=0,to=0,TO=0;
        for(int i=1;i<=n;i++){
            if(i<TO)to=max(to,i+nex[i]);
            else{
                ans++;
                TO=max(i+nex[i],to);
                to=TO;
            }
            //printf("%d %d\n",ans,to);
        }
        pr(ans,'\n');
    }
}
