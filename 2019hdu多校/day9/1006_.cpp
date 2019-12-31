#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define ff first
#define ss second
#define ll long long
#define mp make_pair
#define pb emplace_back

int a[1010],vis[15];
int caze[12][7][4][12],full[12][7][4],mm[12][7][4][12],best[15];
int main() {
	for(int i=0; i<=10; i++)
		for(int o=0; o<=5; o++)
			for(int p=0; p<=2; p++) {
				if((i&&full[i-1][o][p])||(o&&full[i][o-1][p])||(p&&full[i][o][p-1])) {
					full[i][o][p]++;
					continue;
				}
				set<int>s1,s2;
				s1.clear(),s2.clear();
				s1.insert(0);
				for(int j=1; j<=i; j++)s1.insert(j);

				for(int j=1; j<=o; j++) {
					s2.clear();
					for(auto k:s1)s2.insert(k+2);
					for(auto k:s2)s1.insert(k);
				}

				for(int j=1; j<=p; j++) {
					s2.clear();
					for(auto k:s1)s2.insert(k+5);
					for(auto k:s2)s1.insert(k);
				}

				for(auto j:s1)caze[i][o][p][j%10]++;
				for(auto j:s1)mm[i][o][p][j%10]=max(mm[i][o][p][j%10],j/10);
				int sz=9;
				if(*s1.begin()==0)sz++;
				if(s1.size()==sz)full[i][o][p]++;
				caze[i][o][p][0]=i+o*2+p*5;
			}

	int t;
	scanf("%d",&t);
	while(t--) {
		int n,gg=0;
		scanf("%d",&n);
		for(int i=1; i<=n; i++) {
			scanf("%d",&a[i]);
			if(a[i]%10)gg++;
			else a[i]=a[i]/10;
		}
		if(gg) {
			printf("-1\n");
			continue;
		}

		sort(a+1,a+1+n);
		memset(vis,0,sizeof vis);
		memset(best,0,sizeof best);
		for(int i=1; i<=n; i++)vis[a[i]%10]++,best[a[i]%10]=max(best[a[i]%10],a[i]/10);
		int ans=1e9;

		if(vis[0]==n) {
			printf("%d\n",a[n]/10);
			continue;
		}

		for(int step=1; step<=17; step++) {
			for(int i=0; i<=step&&i<=10; i++)
				for(int o=0; o<=step&&o<=5; o++) {
					int p=step-i-o;
					if(p<0||p>2)continue;
					if(full[i][o][p]) {
						int maxx=0;
						for(int j=0; j<=9; j++)maxx=max(maxx,best[j]-mm[i][o][p][j]);
						//printf("%d %d %d %d %d\n",i,o,p,maxx,i+o+p+maxx);
						ans=min(ans,i+o+p+maxx);
						continue;
					}
					gg=0;
					for(int j=1; j<=9; j++)
						if(vis[j]&&!caze[i][o][p][j]) {
							gg++;
							break;
						}
					if(!gg){
						int maxx=0;
						for(int j=0; j<=9; j++)maxx=max(maxx,best[j]-mm[i][o][p][j]);
						//printf("%d %d %d %d %d\n",i,o,p,maxx,i+o+p+maxx);
						ans=min(ans,i+o+p+maxx);
					}
				}
		}
		printf("%d\n",ans);
	}
}
/*
1 6
20 40 60 100 200 210
*/
