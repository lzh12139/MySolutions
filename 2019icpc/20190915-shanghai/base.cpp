#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define ff first
#define ss second
#define mp make_pair
#define pb emplace_back
int sum[1000010],a[2010];
int main(){
    int t,kase=1;scanf("%d",&t);
    while(t--){
        int n,m;scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++){
            int l,r;scanf("%d%d",&l,&r);
            a[2*i-1]=l+1,a[2*i]=r+2;
            sum[l+1]++,sum[r+2]--;
        }
        sort(a+1,a+1+2*m);
        int cnt=unique(a+1,a+1+2*m)-a-1,ans=0;
        //for(int i=1;i<=cnt;i++)printf("-%d %d\n",a[i],sum[a[i]]);
        for(int i=1;i<=cnt;i++){
            sum[a[i]]+=sum[a[i-1]];
            if(sum[a[i]]&1){
                if(i!=cnt)ans+=a[i+1]-a[i];
                else ans+=n-a[i]+1;
            }
        }
        for(int i=1;i<=cnt;i++)sum[a[i]]=0;
        printf("Case #%d: %d\n",kase++,ans);
    }
}