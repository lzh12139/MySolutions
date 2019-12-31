#include <iostream>
#include <cstring>
using namespace std;
#define N 80
const long long M=1000000007;
int mat_size;
struct matrix{
    long long mat[N][N];
    matrix(){memset(mat,0,sizeof mat);}
    matrix operator * (const matrix& b) const{
        matrix c;
        for (int i=0;i<mat_size;++i)
            for (int j=0;j<mat_size;++j){
                c.mat[i][j]=0;
                for (int k=0;k<mat_size;++k)
                    c.mat[i][j]=(c.mat[i][j]+mat[i][k]*b.mat[k][j]%M)%M;
            }
        return c;
                    
    }
    static matrix unit(){
        matrix c;
        memset(c.mat,0,sizeof(c));
        for (int i=0;i<mat_size;++i) c.mat[i][i]=1;
        return c;
    }
};
long long qpow(long long x,long long y){
    long long ans=1;
    while (y){
        if (y&1) ans=ans*x%M;
        x=x*x%M;
        y>>=1;
    }
    return ans;
}
matrix mpow(matrix x,long long y){
    matrix ans=matrix::unit();
    while (y){
        if (y&1) ans=ans*x;
        x=x*x;
        y>>=1;
    }
    return ans;
}
long long a[N][N];
bool gauss(int n){
    for (int i=1;i<=n;++i){
        int k=i;
        for (int j=i+1;j<=n;++j)
            if (a[j][i]!=0) {k=j; break;}
        long long del=a[k][i];
        if (i!=k) for (int j=1;j<=n+1;++j) swap(a[i][j],a[k][j]);
        del=qpow(del,M-2);
        for (int j=1;j<=n+1;++j) a[i][j]=a[i][j]*del%M;
        for (int k=1;k<=n;++k)
            if (k!=i){
                del=a[k][i];
                //del=qpow(del,M-2);
                for (int j=i;j<=n+1;++j) a[k][j]=(a[k][j]-a[i][j]*del%M+M)%M;
            }
    }
    return true;
}
long long f[1001];
long long p[1001];

matrix t;
int main(){
    int T;
    scanf("%d",&T);
    while (T--){
        long long n;
        int k;
        
        scanf("%d%lld",&k,&n);
        for (int i=1;i<=2*k;++i) scanf("%lld",&f[i]);

        if (n<k){
            long long ans=0;
            for (int i=1;i<=n;++i) ans=(ans+f[i])%M;
            printf("%lld\n",ans);
        } else {
            memset(a,0,sizeof(a));
            for (int i=1;i<=k;++i){
                for (int j=1;j<=k+1;++j){
                    a[i][j]=f[i+j-1];
                }
            }
            gauss(k);
            for (int i=1;i<=k;++i){
                p[i]=a[i][k+1];
            }

            mat_size=k+1;
            n-=k;
            f[k+1]=0;
            for (int i=1;i<=k;++i)
                f[k+1]=(f[k+1]+f[i])%M;

            memset(t.mat,0,sizeof(t.mat));
            for (int i=0;i<k-1;++i) t.mat[i][i+1]=1;
            for (int i=0;i<k;++i) t.mat[k-1][i]=p[i+1];
            for (int i=0;i<k;++i) t.mat[k][i]=p[i+1];
            t.mat[k][k]=1;

            t=mpow(t,n);
            
            long long ans=0;
            for (int i=0;i<=k;++i)
                ans=(ans+f[i+1]*t.mat[k][i]%M)%M;

            printf("%lld\n",ans);
        }

    }
}