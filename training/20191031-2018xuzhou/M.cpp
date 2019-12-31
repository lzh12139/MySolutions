#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
pii a[1010],b[1010];
struct node{
	int l,r,n;
};
node range[3010];
int ansn[1010],anstmp[1010];
int sum[2010];
ll mul(pii x,pii y){
	return 1ll*x.first*y.second-1ll*x.second*y.first;
}
pii sub(pii x,pii y){
	return make_pair(x.first-y.first,x.second-y.second);
}
bool judge(int n){
	ll pend=0;
	for(int i=2;i<n;i++)
		pend+=mul(sub(a[i],a[1]),sub(a[i+1],a[1]));
	return pend<0;
}
int main(){
	//freopen("1.in","r",stdin);
	int t;scanf("%d",&t);
	while (t--){
		int n,m;scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%d%d",&a[i].first,&a[i].second);
			sum[i]=sum[i+n]=0;
		}
		for(int i=1;i<=m;i++)
			scanf("%d%d",&b[i].first,&b[i].second);

		if(judge(n))reverse(a+1,a+1+n);

		for(int i=1;i<=m;i++){
			pii l=sub(a[1],b[i]),r=sub(a[1],b[i]);
			int ln=1,rn=1;
			for(int j=2;j<=n;j++){
				pii x=sub(a[j],b[i]);
				if(mul(x,l)<=0)l=x,ln=j;
				if(mul(x,r)>=0)r=x,rn=j;
			}
			//printf("%d %d\n",ln,rn);
			if(ln==n){
				ln=1;
			}
			else {
				ln++;
				if(ln>rn)rn+=n;
			}
			sum[ln]++,sum[rn+1]--;
			//if(ln<rn)ln+=n,swap(ln,rn);
			range[i].l=ln,range[i].r=rn,range[i].n=i;
			//printf("%d %d\n",ln,rn);
		}
		for(int i=1;i<=2*n;i++)sum[i]+=sum[i-1];
		//printf("\n");
		int gg=0;
		for(int i=1;i<=n;i++)
			if(!sum[i]&&!sum[i+n]){
				gg++;break;
			}
		if(gg){printf("-1\n");continue;}
		for(int i=1;i<=m;i++){
			range[i+m]=range[i];
			range[i+m].l+=n,range[i+m].r+=n;
			//range[i+2*m]=range[i];
			//range[i+2*m].l+=n,range[i+2*m].r+=n;
		}
		sort(range+1,range+1+2*m,[](node a,node b){
			if(a.l!=b.l)return a.l<b.l;
			return a.r>b.r;
		});
		/*printf("range:\n");
		for (int i=1;i<=2*m;++i)
			printf("%d %d %d\n",range[i].l,range[i].r,range[i].n);
		printf("-------------------\n");*/

		int ans=100000;
		int st=1;
		for(int i=1;i<=n;i++){
			while (range[st].l<i) ++st;
			if (range[st].l>i) continue;

			int R=range[st].r,maxx=range[st].r,tmp=1,maxn=i;
			anstmp[1]=range[st].n;
			for(int j=st+1;j<=2*m;j++){
				//printf("----%d %d----\n",range[j].l,R);
				if(range[j].l>R+1){
					//printf("%d %d %d %d\n",i,j,maxx,maxn);
					tmp++;
					anstmp[tmp]=range[maxn].n;
					R=maxx;
					if(maxx<range[j].r)maxx=range[j].r,maxn=j;
					if(R>=i+n-1) break;
				}
				if(maxx<range[j].r)maxx=range[j].r,maxn=j;
			}
			if(R<i+n-1) continue;
			if(ans>tmp){
				ans=tmp;
				for(int j=1;j<=tmp;j++)ansn[j]=anstmp[j];
				/*printf("%d\n",tmp);
				for(int j=1;j<=tmp;j++)printf("%d ",anstmp[j]);
				printf("\n");*/
			}
		}
		if (ans==100000) printf("-1\n");
		else {
			printf("%d\n",ans);
			for(int i=1;i<=ans;i++)printf("%d%c",ansn[i]," \n"[i==ans]);
		}
	}
}