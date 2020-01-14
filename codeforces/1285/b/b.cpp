/**
 * Author: lzh12139
 * Time: 2020-01-10 22:10:01
**/

#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define mp(x, y) make_pair(x, y)
#define pb(x) emplace_back(x)
#define _yes printf("YES\n")
#define _no printf("NO\n")

typedef long long ll;
typedef vector<int> V;
typedef pair<ll, int> pii;

int a[100010];
ll sum[100010];
int main(){
    int t;scanf("%d",&t);
    while(t--){
        int n;scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",a+i);
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        sum[n]=a[n];
        for(int i=n-1;i>=1;i--)sum[i]=sum[i+1]+a[i];
        for(int i=1;i<=n;i++)pq.push(make_pair(sum[i],i));

        int ans=0;
        if(sum[1]-pq.top().ff>=sum[1]){
            _no;continue;
        }

        pq.push(make_pair(0,n+1));

        ll cur=sum[1];
        
        for(int i=1;i<n;i++){
            cur-=a[i];
            while(!pq.empty()&&pq.top().ss<=i)pq.pop();

            //printf("%lld\n",cur-pq.top().ff);
            if(!pq.empty()&&cur-pq.top().ff>=sum[1]){
                ans=1;break;
            }
        }

        if(ans)_no;
        else _yes;
    }
}