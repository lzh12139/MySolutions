#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define ff first
#define ss second

const int N=1e6+10;
int buffer_inf[N],buffer[N];
pii p[N],out[N];

int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        for(int i=1;i<=n;i++)scanf("%d%d",&p[i].ff,&p[i].ss);
        for(int i=1;i<=m;i++)scanf("%d",&buffer_inf[i]),buffer[i]=0,out[i].ff=out[i].ss=0;
        sort(p+1,p+1+n);

        int yichu=0,last=p[1].ff,time=p[1].ff;
        ll ans=0;
        for(int i=1;i<=n;i++){
            if(p[i].ff<=time){
                if(buffer[p[i].ss]<buffer_inf[p[i].ss])buffer[p[i].ss]++;
                else {
                    if(last<time)last++;
                    else yichu++;
                }
            }
            else {
                while(p[i].ff>time){
                    if(yichu)ans+=--yichu;
                    else break;
                    time++;last++;
                }
                time=p[i].ff;i--;
            }
            //printf("%d %d %d %lld\n",yichu,last,time,ans);
        }
        ans+=1ll*yichu*(yichu-1)/2;
        printf("%lld\n",ans);
    }
}
/*
5 1
1 1
1 1
9 1
9 1
9 1
1
*/