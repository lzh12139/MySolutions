#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define ff first
#define ss second
#define ll long long
#define mp make_pair
#define pb emplace_back

map<pii,int>m;
int x[100010],y[100010];
pii xans[100010],yans[100010];
int main(){
	int n,r;scanf("%d%d",&n,&r);
	for(int i=1;i<=n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		x[a]++,y[b]++,m[mp(a,b)]++;
	}
	for(int i=1;i<=100000;i++){
		int cmp=x[i];
		if(i+r<=100000)cmp+=x[i+r];
		if(i+r+r<=100000)cmp+=x[i+r+r];
		xans=mp(cmp,i);
		if(cmp==6){
			printf("6\n");return 0;
		}
	}
	for(int i=1;i<=100000;i++){
		int cmp=y[i];
		if(i+r<=100000)cmp+=y[i+r];
		if(i+r+r<=100000)cmp+=y[i+r+r];
		yans=mp(cmp,i);
		if(cmp==6){
			printf("6\n");return 0;
		}
	}
	sort(xans+1,xans+1+n,greater<pii>());
	sort(yans+1,yans+1+n,greater<pii>());
	int rx=find(xans,n,xans[1].ff),ry=find(yans,n,yans[1].ff);
}
