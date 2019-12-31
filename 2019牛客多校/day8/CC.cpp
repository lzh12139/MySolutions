#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define ff first
#define ss second
#define ll long long
#define mp make_pair
#define pb emplace_back

int ans[1050][1050];
int main() {
	int n;
	scanf("%d",&n);
	if(n==2) {
		printf("1 1\n");
		printf("1 -1\n");
		return 0;
	}
	for(int i=1; i<=4; i++)ans[1][i]=1;
	ans[2][1]=ans[2][2]=ans[3][1]=ans[3][3]=ans[4][2]=ans[4][3]=1;
	ans[2][3]=ans[2][4]=ans[3][2]=ans[3][4]=ans[4][1]=ans[4][4]=-1;
	for(int j=4; j!=n; j<<=1) {
		for(int i=1; i<=j; i++)for(int o=j+1; o<=j+j; o++)ans[i][o]=ans[i][o-j];
		for(int i=j+1; i<=j+j; i++)for(int o=1; o<=j; o++)ans[i][o]=ans[i-j][o];
		for(int i=j+1; i<=j+j; i++)for(int o=j+1; o<=j+j; o++)ans[i][o]=-ans[i-j][o-j];
	}
	for(int i=1; i<=n; i++)for(int o=1; o<=n; o++)printf("%d%c",ans[i][o]," \n"[o==n]);
}
