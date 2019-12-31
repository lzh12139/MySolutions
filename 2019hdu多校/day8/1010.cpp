#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define ff first
#define ss second
#define ll long long
#define mp make_pair
#define pb emplace_back

struct node {
	char s[20];
	int p,t;
	bool operator<(const node &b)const {
		if(p==b.p)return t<b.t;
		return p>b.p;
	}
} a[100010];

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n,d;
		scanf("%d%d",&n,&d);
		for(int i=1; i<=n; i++)scanf("%s%d%d",a[i].s,&a[i].p,&a[i].t);
		if(n*d%10!=5) {
			printf("Quailty is very great\n");
			continue;
		}
		sort(a+1,a+1+n);
		printf("%s\n",a[n*d/10+1].s);
	}
}
