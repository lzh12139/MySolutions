#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define ff first
#define ss second
#define ll long long
#define mp make_pair
#define pb emplace_back

int base[1050];
int ans[1050][1050];
int main() {
	freopen("out.txt","w",stdout);
	int m;
	scanf("%d",&m);
	printf("%d\n",m);
	if(m==2) {
		printf("1 1\n");
		printf("1 -1\n");
		return 0;
	}
	for(int i=1; i<=4; i++)ans[1][i]=1;
	ans[2][1]=ans[2][2]=ans[3][1]=ans[3][3]=ans[4][2]=ans[4][3]=1;
	ans[2][3]=ans[2][4]=ans[3][2]=ans[3][4]=ans[4][1]=ans[4][4]=-1;
	if(m==4) {
		for(int i=1; i<=m; i++)for(int o=1; o<=m; o++)printf("%d%c",ans[i][o]," \n"[o==m]);
		return 0;
	}

	int pre=4,doo;
	for(int j=4; j!=m; j<<=1) {
		doo=pre/8;
		if(doo==0)doo=1;
		for(int i=1; i<=pre; i++)for(int o=pre; o>=1; o--)ans[i][2*o-1]=ans[i][2*o]=ans[i][o];

		for(int i=1; i<=pre/2; i+=2) {// 10101010
			ans[pre+1][i]=ans[pre+1][i+pre/2]=ans[pre+1][i+pre]=ans[pre+1][i+pre+pre/2]=1;
			ans[pre+1][i+1]=ans[pre+1][i+pre/2+1]=ans[pre+1][i+pre+1]=ans[pre+1][i+pre+pre/2+1]=-1;
		}
		for(int i=1; i<=pre/2; i+=2) {// 01011010
			ans[pre+2][i+1]=ans[pre+2][i+pre/2+1]=ans[pre+2][i+pre]=ans[pre+2][i+pre+pre/2]=1;
			ans[pre+2][i]=ans[pre+2][i+pre/2]=ans[pre+2][i+pre+1]=ans[pre+2][i+pre+pre/2+1]=-1;
		}
		for(int i=1; i<=pre/2; i+=2) {// 01100110
			ans[pre+3][i+1]=ans[pre+3][i+pre/2]=ans[pre+3][i+pre+1]=ans[pre+3][i+pre+pre/2]=1;
			ans[pre+3][i]=ans[pre+3][i+pre/2+1]=ans[pre+3][i+pre]=ans[pre+3][i+pre+pre/2+1]=-1;
		}
		for(int i=1; i<=pre/2; i+=2) {// 10010110
			ans[pre+4][i]=ans[pre+4][i+pre/2+1]=ans[pre+4][i+pre+1]=ans[pre+4][i+pre+pre/2]=1;
			ans[pre+4][i+1]=ans[pre+4][i+pre/2]=ans[pre+4][i+pre]=ans[pre+4][i+pre+pre/2+1]=-1;
		}

		for(int i=pre+5; i<=pre+pre; i+=4) {
			int ok=0;
			for(int o=pre+pre/2+1; o<=pre+pre; o+=2)
				if(ans[i-1][o]==1&&ans[i-1][o+1]==-1&&ok<doo) {
					ans[i][o]=-1,ans[i][o+1]=1;
					ok++;
				}
				else ans[i][o]=ans[i-1][o],ans[i][o+1]=ans[i-1][o+1];
			//ans[i][pre+pre-1]=1,ans[i][pre+pre]=-1;
			// i
			for(int o=1; o<=pre/2; o++)ans[i][o]=ans[i][o+pre/2]=ans[i][o+pre]=ans[i][o+pre+pre/2];
			// i+1
			for(int o=pre+1; o<=pre+pre; o++)ans[i+1][o]=ans[i][o];
			for(int o=1; o<=pre; o++)
				if(ans[i][o]<0)ans[i+1][o]=1;
				else ans[i+1][o]=-1;
			// i+2
			for(int o=pre+1; o<=pre+pre/2; o++)
				if(ans[i+1][o]<0)ans[i+2][o]=1;
				else ans[i+2][o]=-1;
			for(int o=pre+pre/2+1;o<=pre+pre;o++)ans[i+2][o]=ans[i+1][o];
			for(int o=1;o<=pre;o++)ans[i+2][o]=ans[i+2][o+pre];
			// i+3
			for(int o=pre+1; o<=pre+pre; o++)ans[i+3][o]=ans[i+2][o];
			for(int o=1; o<=pre; o++)
				if(ans[i+2][o]<0)ans[i+3][o]=1;
				else ans[i+3][o]=-1;
		}
		pre<<=1;
	}
	for(int i=1; i<=m; i++)for(int o=1; o<=m; o++)printf("%d%c",ans[i][o]," \n"[o==m]);
}
