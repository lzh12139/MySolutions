#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define ff first
#define ss second
#define mp make_pair
pii p[100010];
int a[100010];
int main(){
    //srand(time(0));
    int n;scanf("%d",&n);
    //n=50;
    ll maxx=0;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&p[i].ff,&p[i].ss);
        int mod=1e9;
        //p[i].ff=rand()*rand()%mod,p[i].ss=rand()*rand()%mod;
        if(p[i].ff>p[i].ss)swap(p[i].ff,p[i].ss);
        maxx=max(maxx,1ll*p[i].ff*p[i].ss);
    }
    ll ans=0;
    sort(p+1,p+1+n);
    //for(int i=1;i<=n;i++)printf("%d %d\n",p[i].ff,p[i].ss);
    for(int i=n;i>=1;i--)a[i]=max(p[i].ss,a[i+1]);
    for(int i=1;i<n;i++){
        ll cmp=0;
        cmp=1ll*p[i].ff*min(p[i].ss,a[i+1]);
        ans=max(ans,cmp);
    }
    //printf("%lld\n",ans);
    if(ans*2>=maxx)printf("%lld.0\n",ans);
    else {
        if(maxx&1)printf("%lld.5\n",maxx/2);
        else printf("%lld.0\n",maxx/2);
    }
/*
    ans=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++){
            ll tmp=0;
            tmp=max(1ll*min(p[i].ff,p[j].ff)*min(p[i].ss,p[j].ss),
                1ll*min(p[i].ff,p[j].ss)*min(p[i].ss,p[j].ff));
            ans=max(ans,tmp);
        }
    printf("%lld\n",ans);*/
}