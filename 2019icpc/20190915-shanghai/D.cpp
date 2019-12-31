#include <fstream>
#include <iostream>
using namespace std;
int p[21];
int num[3001];
int F(int n,int m){
    return p[n-m]-2*n+m;
}
int ans=0;
void dfs(int n,int q,int s){
    if (n==0){
        if (q==s) ++ans;
    } else {
        for (int i=1;i<=3000;++i){
            if (q*i>s+i+n-1) break;
            dfs(n-1,q*i,s+i);
        }
    }
}
int main(){
    p[0]=1;
    ofstream fout("out.txt");
    for (int i=1;i<=20;++i){
        p[i]=p[i-1]*2;
    }
    num[0]=0;
    for (int i=1;i<=3000;++i){
        int j=num[i-1];
        while (F(i,j)>=0 && j<=i){
            //printf("F(%d,%d)=%d\n",i,j,F(i,j));
            ++j;
        }
        num[i]=j-1;
    }
    for (int n=1;n<=3000;++n){
        ans=0;
        cout<<"n="<<n<<endl;        
        dfs(n-num[n],1,num[n]);
        fout<<ans<<",";
    }
}