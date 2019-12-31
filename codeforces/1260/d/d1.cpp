/**
 * Author: hrynb
 * Time: 2019-11-27 23:32:44
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
    int m=10,n=10,k=10,t=20;
    fprintf(in,"%d %d %d %d\n",m,n,k,t);
    for(int i=1;i<=m;i++)fprintf(in,"%d ",rand()%100+1);
    fprintf(in,"\n");
    for(int i=1;i<=k;i++)fprintf(in,"%d %d %d\n",1,rand()%10+1,rand()%100+1);
}
