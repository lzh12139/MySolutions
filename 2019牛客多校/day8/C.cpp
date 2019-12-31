#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define ff first
#define ss second
#define ll long long
#define mp make_pair
#define pb emplace_back

int a[10000000][33],m,ok=0;
void dfs(int x,vector<int>v) {
	if(ok)return;
	if(x>a[0][0]||v.size()==m-1) {
		if(v.size()!=m-1)return;
		for(auto i:v) {
			for(int o=1; o<=m; o++)
				printf("%d ",a[i][o]);
			printf("\n");
		}
		printf("\n");
		ok++;
		return;
	}
	int gg=0;
	for(auto i:v) {
		int cmp=0;
		for(int o=1; o<=m; o++)
			if(a[x][o]==a[i][o])cmp++;
		if(cmp!=m/2) {
			gg++;
			break;
		}
	}
	if(!gg) {
		v.pb(x);
		dfs(x+1,v);
		v.erase(v.end()-1);
		dfs(x+1,v);
	} else {
		dfs(x+1,v);
	}

}
int main() {
	scanf("%d",&m);
	/*if(m==2){
		printf("1 1\n");
		printf("1 -1\n");
		return 0;
	}
	if(m==4){
		printf("0\n");
	}*/
	for(ll i=1; i<(1ll<<m-1); i++) {
		ll cmp=i,b[40],c=0;
		for(int o=0;o<=m;o++)b[o]=0;
		while(cmp) {
			b[++b[0]]=cmp&1;
			if(cmp&1)c++;
			cmp>>=1;
		}
		if(c!=m/2)continue;
		//printf("%d\n",i);
		++a[0][0];
		if(a[0][0]%100000==0)printf("%d %lld\n",a[0][0],i);
		for(int o=1; o<=m; o++)a[a[0][0]][o]=b[o];
		if(a[0][0]>=6000000)break;
	}
	vector<int>res;
	res.clear();
	printf("111---\n");
	dfs(1,res);
}
