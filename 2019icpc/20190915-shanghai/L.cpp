#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define ff first
#define ss second
#define mp make_pair
#define pb emplace_back
ll sum[12][1000010];
void pre(){
    for(int i=2;i<=10;i++){
        for(int o=1;o<=1000000;o++){
            int cmp=o;
            while(cmp){
                sum[i][o]+=cmp%i;
                cmp/=i;
            }
            sum[i][o]+=sum[i][o-1];
        }
    }
}
int main(){
    pre();
    int t,kase=1;scanf("%d",&t);
    while(t--){
        int n,b;scanf("%d%d",&n,&b);
        printf("Case #%d: %lld\n",kase++,sum[b][n]);
    }
}