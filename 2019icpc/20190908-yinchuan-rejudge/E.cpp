#include<cstdio>
#include<cstdlib>
using namespace std;
typedef long long ll;
ll quick_mod(ll a,ll b,ll m){
    ll ans=1;
    a%=m;
    while(b){
        if(b&1)ans=ans*a%m;
        a=a*a%m;
        b>>=1;
    }
    return ans;
}
struct T{
    ll p,d;
};
ll w;
T multi_er(T a,T b,ll m){
    T ans;
    ans.p=(a.p*b.p%m+a.d*b.d%m*w%m)%m;
    ans.d=(a.p*b.d%m+a.d*b.p%m)%m;
    return ans;
}
T power(T a,ll b,ll m){
    T ans;
    ans.p=1,ans.d=0;
    while(b){
        if(b&1)ans=multi_er(ans,a,m);
        b>>=1;
        a=multi_er(a,a,m);
    }
    return ans;
}
ll legendre(ll a,ll p){
    return quick_mod(a,(p-1)>>1,p);
}
ll mod(ll a,ll m){
    a%=m;
    if(a<0)a+=m;
    return a;
}
ll solve(ll n,ll s,ll p){
    if(p==2)return 1;
    if(legendre(n,p)+1==p)return -1;
    ll a=-1,t,cnt=1;
    while(cnt++<=100000){
        a=rand()%p;
        //t=quick_mod(a,s,p)-n;
        t=a*a-n;
        w=mod(t,p);
        if(legendre(w,p)+1==p)break;
    }
    T tmp;
    tmp.p=a,tmp.d=1;
    T ans=power(tmp,(p+1)>>1,p);
    return ans.p;
}
int main(){
    while(1){
        ll n,s,p;scanf("%lld%lld%lld",&n,&s,&p);
        printf("%lld\n",solve(n,s,p));
    }
}