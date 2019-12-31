#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
const int N=2;
const int mod=998244353;
struct mat{
    ll a[N][N];
    mat(){memset(a,0,sizeof a);}
    mat operator*(const mat &b)const{
        mat tmp;
        tmp.a[0][0]=(a[0][0]*b.a[0][0]%mod+a[0][1]*b.a[1][0]%mod)%mod;
        tmp.a[0][1]=(a[0][0]*b.a[0][1]%mod+a[0][1]*b.a[1][1]%mod)%mod;
        tmp.a[1][0]=(a[1][0]*b.a[0][0]%mod+a[1][1]*b.a[1][0]%mod)%mod;
        tmp.a[1][1]=(a[1][0]*b.a[0][1]%mod+a[1][1]*b.a[1][1]%mod)%mod;
        return tmp;
    }
};
mat unit,base,f0;
mat quickpow(ll x){
    mat p=base,res=unit;
    while(x){
        if(x&1)res=res*p;
        p=p*p;
        x>>=1;
    }
    return res;
}
unordered_map<ll,int>mapans;
int main(){
    unit.a[0][0]=unit.a[1][1]=1;
    base.a[0][0]=3,base.a[0][1]=2,base.a[1][0]=1;
    ll q,n,ansn=0,end=-1,xorans=-1;
    scanf("%lld%lld",&q,&n);
    for(int i=1;i<=q;i++){
        ll cur=quickpow(n-1).a[0][0]%mod;

        if(mapans[cur]==i-1&&i!=1){
            end=i-1,xorans=cur;
            break;
        }
        mapans[cur]=i;

        ansn=ansn^cur,n=n^(cur*cur);
    }
    if(end!=-1){
        if((q-end)&1)ansn^=xorans;
    }
    printf("%lld\n",ansn);
}