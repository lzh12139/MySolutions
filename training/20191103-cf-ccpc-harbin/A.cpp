#include<bits/stdc++.h>
using namespace std;
namespace lp{
	// 求min{ B_i * X_i }
	// 约束： A_ij * X_i >= C_j
	// n个约束，每个约束长度为m
	const int N=6010,M=3010;
	const double INF=1e18;
	const double eps=1e-8;
	int n,m;
	double a[M][N],b[M],c[N],v;

	void pivot(int l,int e){
		b[l]/=a[l][e];
		for(int j=1;j<=n;j++)if(j!=e)a[l][j]/=a[l][e];
		a[l][e]=1.0/a[l][e];
		for(int i=1;i<=m;i++)
			if(i!=l&&fabs(a[i][e])>0){
				b[i]-=a[i][e]*b[l];
				for(int j=1;j<=n;j++)
					if(j!=e)a[i][j]-=a[i][e]*a[l][j];
				a[i][e]*=-a[l][e];
			}
		printf("add: c-%d %lf b-%d %lf %lf\n",e,c[e],l,b[l],c[e]*b[l]);
		v+=c[e]*b[l];
		for(int j=1;j<=n;j++)if(j!=e)c[j]-=c[e]*a[l][j];
		c[e]*=-a[l][e];
	}
	double simplex(){
		v=0;
		while(1){
			int e=-1,l=-1;
			for(int i=1;i<=n;i++)if(c[i]>eps){e=i;break;}
			if(e==-1)return v;
			double t=INF;
			for(int i=1;i<=m;i++)
				if(a[i][e]>eps&&t>b[i]/a[i][e]){
					t=b[i]/a[i][e];
					l=i;
				}
			if(l==-1)return INF;
			pivot(l,e);
		}
	}
	void read(){
		int n1,n2;
		scanf("%d%d%d",&m,&n1,&n2);
		n=n1+n2;
		for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)a[i][j]=0;

		for(int i=1;i<=n1;i++){
			int l,r,k;scanf("%d%d%d",&l,&r,&k);
			c[i]=k;
			for(int j=l;j<=r;j++)a[j][i]=1;
		}

		for(int i=1+n1;i<=n2+n1;i++){
			int l,r,k;scanf("%d%d%d",&l,&r,&k);
			c[i]=k;
			for(int j=1;j<l;j++)a[j][i]=1;
			for(int j=r+1;j<=m;j++)a[j][i]=1;
		}

		for(int i=1;i<=m;i++)b[i]=1;
	}
	void out(){
		for(int i=1;i<=n;i++)printf("%lf ",c[i]);printf("\n");
		for(int i=1;i<=m;i++)printf("%lf ",b[i]);printf("\n");
	}
};

int main(){
	freopen("1.in","r",stdin);
	int T;scanf("%d",&T);
	while(T--){
		lp::read();
		lp::out();
		printf("%.0lf\n",lp::simplex());
		lp::out();
	}
}