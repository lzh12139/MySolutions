#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define ff first
#define ss second

int a[1000010];
int main(){
    int n,k;scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)a[i]=1;
    int ans=0,cur=0;
    while(k--){
        int m,cnt=cur;scanf("%d",&m);
        for(int i=1;i*m<=n;i++){
            if(!a[i*m])cnt--;
            else cnt++;
            a[i*m]^=1;
        }
        ans=max(ans,cnt);
        //cout<<cnt<<endl;
        cur=cnt;
    }
    printf("%d\n",ans);
}