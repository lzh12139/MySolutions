#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define ff first
#define ss second
#define ll long long
#define mp make_pair
#define pb emplace_back

pii a[1000010];
int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        int n;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)scanf("%d%d",&a[i].ff,&a[i].ss);
        sort(a+1,a+1+n,greater<pii>());
        a[n+1]=a[1];

        if(n==1) {
            printf("0\n");
            continue;
        }
        ll ans=0,less=0;
        int l=2;
        for(int i=1; i<=n; i++) {
            int cmp=a[i].ff;
            ll add=0;
            while(l<=n+1&&cmp) {
                if(l==i||(i==1&&l==n+1)) {
                    if(i==1&&l==n+1)break;
                    if(cmp<=less)ans+=cmp,less-=cmp,cmp=0,add+=a[l].ss;
                    else ans+=less,cmp-=less,less=0,add+=a[l].ss,l++;
                } else {
                    if(cmp<=less)ans+=cmp,less-=cmp,cmp=0;
                    else if(cmp<=a[l].ss+less)ans+=cmp,a[l].ss-=cmp-less,less=0,cmp=0;
                    else ans+=a[l].ss+less,cmp-=a[l].ss+less,less=0,a[l].ss=0,l++;
                }
            }
            if(cmp<=less)ans+=cmp,less-=cmp,cmp=0;
            else ans+=less,cmp-=less,less=0;
            less+=add;
            //printf("%lld %lld ",ans,less);for(int o=1;o<=n;o++)printf("%d ",a[o].ss);printf("\n");
        }
        printf("%lld\n",ans);
    }
}
/*
1000
4
1 2
3 4
5 6
7 8
*/
