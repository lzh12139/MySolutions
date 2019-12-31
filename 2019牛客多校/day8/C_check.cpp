#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define ff first
#define ss second
#define ll long long
#define mp make_pair
#define pb emplace_back

int a[1050][1050];
int main() {
	freopen("out.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)for(int o=1; o<=n; o++)scanf("%d",&a[i][o]);
	for(int i=1; i<=n; i++)
		for(int o=i+1; o<=n; o++) {
			int cmp=0;
			for(int p=1; p<=n; p++)if(a[i][p]^a[o][p]>0)cmp++;
			if(cmp!=n/2)printf("%d %d\n",i,o);
		}
}
