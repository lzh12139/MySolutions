#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define mp(x, y) make_pair(x, y)
#define pb(x) emplace_back(x)
#define _yes printf("Yes\n")
#define _no printf("No\n")

typedef long long ll;
typedef vector<int> V;
typedef pair<int, int> pii;

pii p[200010];
int x[400010];
ll sum[800010];
int ans[800010];
map<int,int>m;

int main(){
	int t;scanf("%d",&t);
	for(int T=1;T<=t;T++){
		int n;scanf("%d",&n);

		m.clear();
		for(int i=1;i<=4*n+4;i++)sum[i]=ans[i]=0;

		for(int i=1;i<=n;i++){
			scanf("%d%d",&p[i].ff,&p[i].ss);
			x[2*i-1]=p[i].ff,x[2*i]=p[i].ss;
		}
		sort(x+1,x+1+2*n);
		int c=0;
		for(int i=1;i<=2*n;i++)if(!m[x[i]])m[x[i]]=++c;

		for(int i=1;i<=n;i++){
			p[i].ff=2*m[p[i].ff];
			p[i].ss=2*m[p[i].ss];
			sum[p[i].ff]++,sum[p[i].ss+1]--;
		}
		for(int i=1;i<=2*c;i++)sum[i]+=sum[i-1];
		for(int i=1;i<=2*c;i++)
			if(sum[i-1]>1&&sum[i]==1){
				int ok=0;
				for(int j=i;j<=2*c;j++)
					if(sum[j]==1&&sum[j+1]>1){ok=1;break;}
					else if(sum[j]!=1)break;
				if(ok)ans[i]=1;
			}
		for(int i=1;i<=2*c;i++)ans[i]+=ans[i-1];

		sort(p+1,p+1+n);
		/*for(int i=1;i<=n;i++)printf("%d %d\n",p[i].ff,p[i].ss);
		for(int i=1;i<=2*c;i++)printf("%d ",sum[i]);printf("\n");
		for(int i=1;i<=2*c;i++)printf("%d ",ans[i]);printf("\n");*/

		int r=p[1].ss,cnt=1,anss;
		for(int i=1;i<=n;i++){
			if(p[i].ff<=r)r=max(r,p[i].ss);
			else r=p[i].ss,cnt++;
		}

		anss=cnt;
		for(int i=1;i<=n;i++)anss=max(anss,cnt+ans[p[i].ss]-ans[p[i].ff]);
		printf("%d\n",min(n-1,anss));
	}
}