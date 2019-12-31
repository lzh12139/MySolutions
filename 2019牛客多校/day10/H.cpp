#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define ff first
#define ss second
#define ll long long
#define mp make_pair
#define pb emplace_back

int deg[10],v[10];
pii edge[10];
int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		for(int i=1; i<=6; i++)deg[i]=0,v[i]=0;
		for(int i=1; i<=5; i++) {
			scanf("%d%d",&edge[i].ff,&edge[i].ss);
			deg[edge[i].ff]++,deg[edge[i].ss]++;
		}
		for(int i=1; i<=6; i++)v[deg[i]]++;
		if(v[1]==2&&v[2]==4)printf("n-hexane\n");
		else if(v[1]==4&&v[2]==1&&v[4]==1)printf("2,2-dimethylbutane\n");
		else if(v[1]==4&&v[3]==2)printf("2,3-dimethylbutane\n");
		else {
			for(int i=1; i<=6; i++)
				if(deg[i]==3) {
					int cnt=0;
					for(int o=1; o<=5; o++)
						if(edge[o].ff==i&&deg[edge[o].ss]==1)cnt++;
						else if(edge[o].ss==i&&deg[edge[o].ff]==1)cnt++;
					if(cnt==2)printf("2-methylpentane\n");
					else printf("3-methylpentane\n");
					break;
				}
		}
	}
}
