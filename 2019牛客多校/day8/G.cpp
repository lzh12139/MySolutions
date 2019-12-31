#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define ff first
#define ss second
#define ll long long
#define mp make_pair
#define pb emplace_back

char s[100010],t[100010];
int main() {
	scanf("%s",s+1);
	int n=strlen(s+1),ans=0,len=0;
	for(int i=1;i<=n;i++){
		t[++len]=s[i];
		if(len<3)continue;
		if(t[len]==t[len-1]&&t[len-1]==t[len-2])len-=3,ans++;
	}
	printf("%d\n",ans);
}
