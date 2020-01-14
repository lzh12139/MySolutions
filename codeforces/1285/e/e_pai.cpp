#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define mp(x, y) make_pair(x, y)
#define pb(x) emplace_back(x)
#define _yes printf("Yes\n")
#define _no printf("No\n")

typedef long long ll;
typedef vector<int> V;
typedef pair<int, int> pii;

pii p[200010];

int main(){
    srand(time(0));
    auto in=fopen("in3.txt","w"),ans=fopen("ans3.txt","w");
    int T=1000;
    fprintf(in,"%d\n",T);
    while(T--){
        int n=rand()%1000;
        fprintf(in,"%d\n",n);
        for(int i=1;i<=n;i++){
            p[i].ff=rand()%100,p[i].ss=rand()%100+p[i].ff;
            fprintf(in,"%d %d\n",p[i].ff,p[i].ss);
        }

        sort(p+1,p+1+n);
        int anss=0;
        for(int i=1;i<=n;i++){
            int r=-1e9,cnt=1;
            for(int j=1;j<=n;j++)
                if(i!=j){
                    if(r==-1e9)r=p[j].ss;
                    if(p[j].ff<=r)r=max(r,p[j].ss);
			        else r=p[j].ss,cnt++;
                }
            anss=max(anss,cnt);
        }

        fprintf(ans,"%d\n",anss);
    }
}