#include <iostream>
using namespace std;
char s[1000001],t[1000001];
int d[1000001];
int sum[1000001][26];
int solve(int l,int r,int up){
    //--l; ++r;
    int L=l-1,res=r+1;
    while (l<=r){
        int mid=l+r>>1;
        if (sum[mid][up]-sum[L][up]>0) r=mid-1,res=mid;
        else l=mid+1;
    }
    return res;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    scanf("%s%s",s+1,t+1);
    int j=1;
    d[0]=0;
    for (int i=1;i<=n;++i){
        if (j>m) break;
        if (s[i]==t[j]){
            d[j]=i;
            ++j;
        }
    }
    //if (d[m]==0) {printf("-1"); return 0;}
    for (int i=1;i<=n;++i){
        for (int j=0;j<26;++j) sum[i][j]=sum[i-1][j];
        int st=s[i]-'a';
        for (int j=st-1;j>=0;--j) sum[i][j]++;
    }
    int ans=-1;

    //i=0
    int pos=solve(1,n,t[1]-'a');
    if (pos<=n) ans=max(ans,n-pos+1);

    //i=[1..m-1]
    for (int i=1;i<m;++i)
        if (d[i]){
            pos=solve(d[i]+1,n,t[i+1]-'a');
            if (pos<=n) ans=max(ans,i+n-pos+1);
        }

    //i=m
    if (d[m]>0 && n-d[m]>0) ans=max(ans,n-d[m]+m);


    printf("%d\n",ans);
}