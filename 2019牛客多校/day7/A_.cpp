#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define ff first
#define ss second
#define ll long long
#define mp make_pair
#define pb emplace_back

char s[210];
string v[210];
int to[210];
int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		scanf("%s",s);
		int n=strlen(s),l=0,r=-100;
		if(s[0]=='1') {
			for(int i=0; i<n; i++)
				if(s[i]=='0') {
					l=i;
					break;
				}
			if(l==0) {
				for(int i=0; i<n; i++)printf("1");
				printf("\n");
				continue;
			} else {
				for(int i=0; i<l; i++)printf("1");
				printf(" ");
			}
		}
		for(int i=l+1; i<n; i++)
			if(s[i]!='0') {
				r=i;
				break;
			}
		if(r==-100)r=n;
		while(1) {
			//printf("l=%d r=%d\n",l,r);

			/*if(r-l==1) {
				printf("%c\n",s[l]);
				break;
			}*/
			int c=0;
			for(int i=l,cnt=1; i<r; i++,cnt++) {
				v[cnt]="";
				for(int o=0; o<r-l; o++)v[cnt]+=s[(cnt+o)%(r-l)+l];
			}
			sort(v+1,v+1+r-l);
			int gg=0;
			for(int i=0,o=l; i<r-l; i++,o++)
				if(v[1][i]!=s[o]) {
					gg++;
					break;
				}
			//printf("%s\n",v[1].c_str());
			if(gg) {
				for(int i=l; i<r-1; i++)printf("%c",s[i]);
				l=r-1,r=-100;
				for(int i=l+1; i<n; i++)
					if(s[i]!='0') {
						r=i;
						break;
					}
				if(r==-100)r=n;
				if(l>=n) {
					printf("\n");
					break;
				} else printf(" ");
			} else {
				r++;
				if(r==n+1) {
					for(int i=l; i<n; i++)printf("%c",s[i]);
					printf("\n");
					break;
				}
			}
		}
	}
}
