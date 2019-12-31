#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int w[30][30],cant[30],val[30][4],cnt[30],ans;
char s[30];
void dfs(int l,int r,int sum,int cur){
	if(sum>=ans)return;
	if(l==r+1){
        //for(int i=1;i<=r;i++)printf("%d%c",cnt[i]," \n"[i==r]);printf("%d\n",sum);
		ans=min(ans,sum);
		return;
	}
	for(int i=1;i<=w[l][0];i++){
		int v=w[l][i];
		if((cant[v]&cur)==0){
			if(cur&(1<<v)){
				sum+=val[v][++cnt[v]];
				dfs(l+1,r,sum,cur);
				sum-=val[v][cnt[v]--];
			}
			else{
				sum+=val[v][++cnt[v]];
				cur|=1<<v;
				dfs(l+1,r,sum,cur);
				sum-=val[v][cnt[v]--];
				cur-=1<<v;
			}
		}
	}
}
int main(){
	int t;scanf("%d",&t);
	while(t--){
		int n;scanf("%d",&n);
		ans=1e9;
		for(int i=1;i<=n;i++)w[i][0]=cnt[i]=cant[i]=0;
		for(int i=1;i<=n;i++){
			scanf("%s",s+1);
			for(int j=1;j<=n;j++)
				if(s[j]=='1')w[j][++w[j][0]]=i;
		}
		for(int i=1;i<=n;i++){
			scanf("%s",s+1);
			for(int j=1;j<=n;j++)
				if(s[j]=='1')cant[i]|=1<<j;
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&val[i][1]);
			val[i][2]=val[i][1]*val[i][1];
			val[i][3]=val[i][2]*val[i][1];
            val[i][3]-=val[i][2];
            val[i][2]-=val[i][1];
		}

		dfs(1,n,0,0);

		if(ans==1e9)puts("-1");
		else printf("%d\n",ans);
	}
}