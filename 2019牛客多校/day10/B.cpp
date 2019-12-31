#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define ff first
#define ss second
#define ll long long
#define mp make_pair
#define pb emplace_back

char s1[]={" COFFEE"},s2[]={" CHICKEN"};
ll leng[510];
ll b[510];
int les=10;
void dfs(ll n,ll k){
    if(les==0)return;
    if(n<=2){
        if(n==2)for(int i=k;i<=7&&les;i++)printf("%c",s2[i]),les--;
        else for(int i=k;i<=6&&les;i++)printf("%c",s1[i]),les--;
        return;
    }

    if(k>leng[n-2]){
        dfs(n-1,k-leng[n-2]);
    }
    else {
        dfs(n-2,k);
        dfs(n-1,1);
    }
}
int main(){
    b[1]=b[2]=1;
    leng[1]=6,leng[2]=7;
    for(int i=3;i<=60;i++)b[i]=b[i-1]+b[i-2],leng[i]=leng[i-2]+leng[i-1];
    int t;scanf("%d",&t);
    while(t--){
        les=10;
        ll n,k;scanf("%lld%lld",&n,&k);
        while(n>=60||leng[n-2]>=1e12)n-=2;
        dfs(n,k);
        printf("\n");
    }
}
