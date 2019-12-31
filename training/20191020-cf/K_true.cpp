#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MatrixN=4;
const ll mod=1e9+7;
struct matrix{
    ll arr[MatrixN][MatrixN];
    static int n;
    matrix(){memset(arr,0,sizeof(arr));}
    static matrix unit(){
        matrix tmp;
        for (int i=0;i<MatrixN;++i)
            tmp.arr[i][i]=1;
        return tmp;
    }
    matrix operator * (const matrix &b) const{
        matrix tmp;
        for (int i=0;i<MatrixN;++i)
            for (int j=0;j<MatrixN;++j)
                for (int k=0;k<MatrixN;++k)
                    tmp.arr[i][j]=(tmp.arr[i][j]+arr[i][k]*b.arr[k][j]%mod)%mod;
        return tmp;
    }
    matrix set(const ll b[MatrixN][MatrixN]){
        memcpy(arr,b,sizeof(arr));
    }
};

template<typename T>
T QuickPower(T x,long long y,T unit) {
    T ans=unit;
    while (y){
        if (y&1) ans=ans*x;
        x=x*x;
        y=y>>1;
    }
    return ans;
}

int ans[]={0,2,24,96,416,1536,5504,18944,64000,212992,702464};
int main() {
    int n;scanf("%d",&n);
    matrix tmp;
    tmp.arr[0][0]=6,tmp.arr[0][1]=mod-8,tmp.arr[0][2]=mod-8,tmp.arr[0][3]=16;
    tmp.arr[1][0]=1;
    tmp.arr[2][1]=1;
    tmp.arr[3][2]=1;
    matrix cur;
    cur.arr[0][0]=702464;
    cur.arr[1][0]=212992;
    cur.arr[2][0]=64000;
    cur.arr[3][0]=18944;
    if(n<=10){
        printf("%lld\n",ans[n]);
    }
    else{
        n-=10;
        cur=QuickPower(tmp,n,matrix::unit())*cur;
        printf("%lld\n",cur.arr[0][0]);
    }
}