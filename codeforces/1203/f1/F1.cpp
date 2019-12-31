#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define ff first
#define ss second
#define mp make_pair

vector<pii>u,d;
int main(){
	int n,r;scanf("%d%d",&n,&r);
	for(int i=1;i<=n;i++){
		int x,y;scanf("%d%d",&x,&y);
		if(y>=0)u.push_back(mp(x,y));
		else d.push_back(mp(x+y,-y));
	}
	sort(u.begin(),u.end());
	sort(d.begin(),d.end());
	for(auto i:u)
		if(r<i.ff){printf("NO");return 0;}
		else r+=i.ss;
	for(auto i:d)r-=i.ss;
	if(r<0){printf("NO");return 0;}
	for(auto i:d)
		if(r<i.ff){printf("NO");return 0;}
		else r+=i.ss;
	printf("YES");
}