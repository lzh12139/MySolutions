#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define mp make_pair
#define ll long long
#define up(i,a,b) for(int i=(a);i<=(b);i++)
#define down(i,a,b) for(int i=(a);i>=(b);i--)
#define pb emplace_back
typedef pair<int,int> pii;

int a[500010],ans[500010],vis[500010];
int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		scanf("%d",&n);
		up(i,1,n)scanf("%d",&a[i]),vis[i]=vis[i+n]=0,ans[i]=ans[i+n]=0;
		int cnt0=0,cnt1=0,cnt=1,gg=0;
		
		up(i,1,n)
		if(a[i]<0&&-a[i]>n){
			gg++;break;
		}
		else if(a[i]>0&&a[i]<=n){
			gg++;break;
		}
		if(gg){
			printf("-1\n");
			continue;
		}
		
		up(i,1,n)
		if(a[i]<0)ans[++cnt0]=-a[i],vis[-a[i]]++;
		else ans[cnt0+cnt1+n]=a[i],cnt1++,vis[a[i]]++;
		up(i,1,2*n)
		if(!ans[i]) {
			while(vis[cnt])cnt++;
			ans[i]=cnt++;
		}

		printf("ans== ");up(i,1,2*n)printf("%d ",ans[i]);printf("\n");
		set<int>s;
		up(i,1,n)s.insert(ans[i]);
		up(i,1,n)
		if(a[i]<0){
			if(*s.begin()!=-a[i]){
				gg++;break;
			}
			s.erase(s.begin());
			s.insert(ans[i+n]);
		}
		else {
			if(*s.rbegin()!=a[i]){
				gg++;break;
			}
			s.erase(--s.end());
			s.insert(ans[i+n]);
		}

		if(gg){
			printf("-1\n");continue;
		}
		printf("%d",ans[1]);
		up(i,2,2*n)printf(" %d",ans[i]);
		printf("\n");
	}
}
