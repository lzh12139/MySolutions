#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500010],maxx[500010];
int main(){
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(int i=n;i>=1;i--)maxx[i]=max(maxx[i+1],a[i]);
    for(int i=1;i<=n;i++){
        int l=i+1,r=n,ans=-1;
        while(l<=r){
            int mid=l+r>>1;
            if(maxx[mid]>=a[i]+m)l=mid+1,ans=mid;
            else r=mid-1;
        }
        if(ans!=-1)printf("%d",ans-i-1);
        else printf("-1");
        if(i!=n)printf(" ");
    }
}