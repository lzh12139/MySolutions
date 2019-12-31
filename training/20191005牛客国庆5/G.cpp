#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll a,b,c,d;
    while(~scanf("%lld%lld%lld%lld",&a,&b,&c,&d)){
        ll ans=0;
        ans+=((b/2017)-((a-1)/2017))*(d-c+1);
        ans+=((d/2017)-((c-1)/2017))*(b-a+1);
        ans-=((b/2017)-((a-1)/2017))*((d/2017)-((c-1)/2017));
        printf("%lld\n",ans);
    }
}