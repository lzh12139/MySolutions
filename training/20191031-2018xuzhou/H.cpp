#include<bits/stdc++.h>
using namespace std;
int sum[400010];
int to[400010],color[200010];
using pii=pair<int,int>;
pair<pii,int> p[200010];
int main(){
    int t;scanf("%d",&t);
    while(t--){
        int n,k;scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++){
            scanf("%d%d",&p[i].first.first,&p[i].first.second);
            to[2*i-1]=p[i].first.first;
            to[2*i]=p[i].first.second;
            p[i].second=i;
        }
        sort(to+1,to+1+2*n);
        int cnt=1;
        for(int i=2;i<=2*n;i++)
            if(to[i-1]!=to[i])to[++cnt]=to[i];
        for(int i=1;i<=n;i++){
            p[i].first.first=lower_bound(to+1,to+1+cnt,p[i].first.first)-to;
            p[i].first.second=lower_bound(to+1,to+1+cnt,p[i].first.second)-to;
            //printf("%d %d\n",p[i].first,p[i].second);
        }
        sort(p+1,p+1+n,[](pair<pii,int> a,pair<pii,int> b){
            if(a.first!=b.first) return a.first<b.first;
            return a.second<b.second;
        });
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        for(int i=1;i<=k;i++)pq.push(make_pair(0,i));

        for(int i=1;i<=n;i++){
            pii x=pq.top();pq.pop();
            color[p[i].second]=x.second;
            pq.push(make_pair(p[i].first.second,x.second));
        }

        for(int i=0;i<=2*cnt+2;i++)sum[i]=0;
        for(int i=1;i<=n;i++)sum[p[i].first.first+1]++,sum[p[i].first.second+1]--;
        int ans=0;
        for(int i=1;i<=cnt+1;i++){
            sum[i]+=sum[i-1];
            if(sum[i]>=k)ans+=to[i]-to[i-1];
        }
        printf("%d\n",ans);
        for(int i=1;i<=n;i++)printf("%d%c",color[i]," \n"[i==n]);
    }
}