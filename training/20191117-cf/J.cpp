#include<bits/stdc++.h>
using namespace std;
int a[510][510],sum[510][510],ans[510][510];
char s[510];
int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s",s+1);
        for(int j=1;j<=n;j++)
            a[i][j]=s[j]-'0',sum[i][j]=sum[i][j-1]+a[i][j];
    }

    for(int i=n;i>=1;i--)
        for(int j=i+1;j<=n;j++){
            if(i+1>j)continue;
            if(sum[i][j]-sum[i][i]==a[i][j])ans[i][j]=1;
        }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            printf("%d",ans[i][j]);
        printf("\n");
    }
}