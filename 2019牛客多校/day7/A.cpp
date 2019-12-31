#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define ff first
#define ss second
#define ll long long
#define mp make_pair
#define pb emplace_back

char s[220];
int check(int l,int r) {
	string str="",pre;
	for(int i=l; i<=r; i++)str+=s[i];
	pre=str;
	for(int i=l; i<r; i++) {
		pre.erase(pre.begin());
		pre+=s[i];
		if(pre<str)return 0;
	}
	return 1;
}
int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		scanf("%s",s+1);
		int n=strlen(s+1);
		for(int i=1; i<=n; i++)
			for(int o=n; o>=i; o--) {
				if(check(i,o)) {
					for(int j=i; j<=o; j++)printf("%c",s[j]);
					if(o==n)printf("\n");
					else printf(" ");
					i=o;
					break;
				}
			}
	}
}
