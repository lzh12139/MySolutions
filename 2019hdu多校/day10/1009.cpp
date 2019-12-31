#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define ff first
#define ss second
#define ll long long
#define mp make_pair
#define pb emplace_back
#define check(x,y) a[x][y]==1&&(!a[x-1][y]||!a[x+1][y])&&(!a[x][y-1]||!a[x][y+1])

int a[2010][2010];
int dd[4][2]= {0,-1,0,1,-1,0,1,0};
int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n,m,q;
		scanf("%d%d%d",&n,&m,&q);
		for(int i=1; i<=n; i++)for(int o=1; o<=m; o++)a[i][o]=1;
		for(int i=0; i<=n+1; i++)a[i][0]=a[i][m+1]=-1;
		for(int i=1; i<=m; i++)a[0][i]=a[n+1][i]=-1;
		int less=n*m;
		for(int qaq=1; qaq<=q; qaq++) {
			int x,y,ans=0;
			scanf("%d%d",&x,&y);
			if(less==0){
				printf("0\n");continue;
			}
			queue<pii>q;
			if(a[x][y])a[x][y]=0,ans++;
			for(int i=0; i<=3; i++)
				if(check(x+dd[i][0],y+dd[i][1]))ans++,q.push(mp(x+dd[i][0],y+dd[i][1])),
					a[x+dd[i][0]][y+dd[i][1]]=0;
			while(!q.empty()) {
				pii tp=q.front();
				q.pop();
				for(int i=0; i<=3; i++)
					if(check(tp.ff+dd[i][0],tp.ss+dd[i][1]))ans++,q.push(mp(tp.ff+dd[i][0],tp.ss+dd[i][1])),
						a[tp.ff+dd[i][0]][tp.ss+dd[i][1]]=0;
			}
			less-=ans;
			printf("%d\n",ans);
		}
	}
}
