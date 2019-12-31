#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define ff first
#define ss second
#define ll long long
#define mp make_pair
#define pb emplace_back

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		pii a1,a2,b1,b2;
		scanf("%d%d%d%d",&a1.ff,&a1.ss,&a2.ff,&a2.ss);
		scanf("%d%d%d%d",&b1.ff,&b1.ss,&b2.ff,&b2.ss);
		if(a1==b1&&a2==b2)puts("2");
		else {
			int ok=0;
/*
			if(b2.ff<=a1.ff||a2.ff<=b1.ff)ok++;
			if(b2.ss<=a1.ss||a2.ss<=b1.ss)ok++;
			if(ok==2) {
				puts("3");
				continue;
			}

			ok=0;
			if(a2.ff<=b1.ff||b2.ff<=a1.ff)ok++;
			if(a2.ss<=b1.ss||b2.ss<=a1.ss)ok++;
			if(ok==2) {
				puts("3");
				continue;
			}
*/
			int l=max(a1.ff,b1.ff),r=min(a2.ff,b2.ff),
			    d=max(a1.ss,b1.ss),u=min(a2.ss,b2.ss);

			if(l>=r||d>=u) {
				printf("3\n");
				continue;
			}

			int ans=0;
			ok=0;

			if(l==a1.ff)ok++;
			if(r==a2.ff)ok++;
			if(d==a1.ss)ok++;
			if(u==a2.ss)ok++;

			if(ok==4)ans++;
			else if(ok==3)ans+=2;
			else if(ok==2) {
				if((l==a1.ff&&r==a2.ff)||(d==a1.ss&&u==a2.ss))ans+=3;
				else ans+=2;
			} else ans+=2;

			ok=0;
			if(l==b1.ff)ok++;
			if(r==b2.ff)ok++;
			if(d==b1.ss)ok++;
			if(u==b2.ss)ok++;

			if(ok==4)ans++;
			else if(ok==3)ans+=2;
			else if(ok==2) {
				if((l==b1.ff&&r==b2.ff)||(d==b1.ss&&u==b2.ss))ans+=3;
				else ans+=2;
			} else ans+=2;

			printf("%d\n",ans);
		}
	}
}
/*
0 0 3 1
1 0 2 1
*/
