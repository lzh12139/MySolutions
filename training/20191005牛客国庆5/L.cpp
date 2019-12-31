#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    const ll mod=1e9+7;
    const ll inv24=(mod+1)/24;
    while(~scanf("%d",&n)){
        ll sum1=0,sum2=0,sum3=0,sum4=0;
        for(int i=1;i<=n;i++){
            ll x;scanf("%lld",&x);
            sum1=(sum1+x)%mod;
            sum2=(sum2+x*x%mod)%mod;
            sum3=(sum3+x*x%mod*x%mod)%mod;
            sum4=(sum4+x*x%mod*x%mod*x%mod)%mod;
        }
        if(n<=3){printf("0\n");continue;}
        ll ans=0;
        ans=sum1*sum1%mod*sum1%mod*sum1%mod;
        ans=(ans-6*sum2%mod*sum1%mod*sum1%mod+mod)%mod;
        ans=(ans+3*sum2%mod*sum2%mod)%mod;
        ans=(ans+8*sum3%mod*sum1%mod+mod)%mod;
        ans=(ans-6*sum4%mod+mod)%mod;
        printf("%lld\n",ans*inv24%mod);
    }
}