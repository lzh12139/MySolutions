#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define ff first
#define ss second
#define ll long long
#define mp make_pair
#define pb emplace_back

vector<pii> l,r,u,d;
bool cmp(pii a,pii b){
	if(a.y<b.y)
}
int main(){
	int t;scanf("%d",&t);
	while(t--){
		int n,m,k;scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=k;i++){
			int x,y;char s[10];
			scanf("%d%d%d",&x,&y,s+1);
			if(s[1]=='L')l.pb(mp(x,y));
			else if(s[1]=='R')r.pb(mp(x,y));
			else if(s[1]=='U')u.pb(mp(x,y));
			else d.pb(mp(x,y));
		}
		sort(l.begin(),l.end());
		sort(u.begin(),u.end());
		sort(r.begin(),r.end());
		sort(d.begin(),d.end());
	}
}
