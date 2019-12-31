#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define ff first
#define ss second
#define ll long long
#define mp make_pair
#define pb emplace_back

char s[1010];
int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		scanf("%s",s+1);
		int n=strlen(s+1);
		int gg=0;
		for(int i=1; i<=n; i++) {
			if(s[i]!='y'&&s[i]!='z')break;
			if(s[i]=='z') {
				s[i]='b';
				break;
			}
		}
		printf("%s\n",s+1);
	}
}
