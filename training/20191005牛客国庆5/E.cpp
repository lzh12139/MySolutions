#include<bits/stdc++.h>
using namespace std;
int a[5010],b[5010],ans[5010],p[5010];
int find(int x,int l,int r){
	while(l<=r){
		int mid=l+r>>1;
		if(x>=b[mid])l=mid+1;
		else r=mid-1;
	}
	return l;
}
void LIS(int l,int r){
	int len=1;
	b[1]=a[l],ans[l]=1;
	for(int i=l+1;i<=r;i++){
		if(a[i]>b[len])b[ans[i]=++len]=a[i];
		else b[ans[i]=find(a[i],1,len)]=a[i];
	}
}
const int inf=1e9;
int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		LIS(1,n);
		//for(int i=1;i<=n;i++)printf("%d%c",ans[i]," \n"[i==n]);
		for(int i=1;i<=n;i++){
			for(int o=1;o<=n;o++)p[o]=inf;p[1]=0;
			int ansn=0;
			for(int o=1;o<i;o++){
				p[ans[o]]=min(a[o],p[ans[o]]);
				ansn^=ans[o]*ans[o];
			}
			for(int o=i+1;o<=n;o++)
				if(a[o]>p[ans[o]-1]){
					p[ans[o]]=min(p[ans[o]],a[o]);
					ansn^=ans[o]*ans[o];
				}
				else {
					p[ans[o]-1]=min(p[ans[o]-1],a[o]);
					ansn^=(ans[o]-1)*(ans[o]-1);
				}
			printf("%d%c",ansn," \n"[i==n]);
		}
	}
}