/**
 * Author: hrynb
 * Time: 2019-11-27 22:41:48
**/

#include<bits/stdc++.h>
using namespace std;
#define mem(x, y) memset(x, (y), sizeof x)
#define ff first
#define ss second
#define mp(x, y) make_pair(x, y)
#define pb(x) emplace_back(x)
#define sc(a) scanf("%d", &a)
#define scl(a) scanf("%lld", &a)
#define scs(a) scanf("%s", a)
#define pr(a, b) printf("%d%c", a, b)
#define prl(a, b) printf("%ll%c", a, b)
#define all(v) v.begin(), v.end()
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define _yes printf("Yes\n")
#define _no printf("No\n")

typedef long long ll;
typedef vector<int> V;
typedef pair<int, int> pii;
typedef map<int, int> mii;

int main(){
    srand(time(0));
    auto in=fopen("in2.txt","w");
    auto out=fopen("ans2.txt","w");
    int t=1000;
    fprintf(in,"%d\n",t);
    for(int i=1;i<=t;i++){
        int a=rand()%50+1,b=rand()%50+1,k=rand()%50+2;
        fprintf(in,"%d %d %d\n",a,b,k);
        vector<pii>v;
        for(int i=1;i<=b;i++)v.push_back(mp(a*i,1));
        for(int i=1;i<=a;i++)v.pb(mp(b*i,2));
        sort(v.begin(),v.end());
        int c1=0,c2=0,gg=0;
        if(v[0].second==1)c1=1;
        else c2=1;
        for(int i=1;i<v.size();i++){
            if(v[i-1].first==v[i].first){
                if(c1){
                    if(c1+1<k)c1++;
                    else c1=0,c2=1;
                }
                else{
                    if(c2+1<k)c2++;
                    else c2=0,c1=1;
                }
            }
            else if(v[i-1].second!=v[i].second){
                c1=c2=0;
                if(v[i].second==1)c1++;
                else c2++;
            }
            else if(v[i].second==1){
                c1++;
                if(c1==k){gg++;break;}
            }
            else {
                c2++;
                if(c2==k){gg++;break;}
            }
        }
        if(gg)fprintf(out,"REBEL\n");
        else fprintf(out,"OBEY\n");
    }
}
