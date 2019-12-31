#include<bits/stdc++.h>
using namespace std;

const int N=5e4;
const double PI=acos(-1.0);
double a[100000];
typedef pair<double,int> pii;
vector<pii>ind[100000];
int ans[60000];
int find(int r,double x){
	int l=1;
	while(l<=r){
		int mid=l+r>>1;
		if(a[mid]<x)l=mid+1;
		else r=mid-1;
	}
	return l;
}
int main(){
	int cnt=0,cur=1;
	a[cnt]=0;
	while(cnt<25000){
		double tmp=sin(cur);
		cur++;
		if(tmp<0)continue;

		if(tmp>a[cnt])a[++cnt]=tmp,ind[cnt].push_back(pii{tmp,cur-1});
		else{
			int x=find(cnt,tmp);
			a[x]=tmp,ind[x].push_back(pii{tmp,cur-1});
		}
	}

	for(int i=1;i<=25000;i++)sort(ind[i].begin(),ind[i].end());
	pii pre=ind[25000].back();
	ans[1]=pre.second;
	for(int i=24999,j=2;i>=1;i--,j++){
		pre=*(--lower_bound(ind[i].begin(),ind[i].end(),pre));
		ans[j]=pre.second;
	}
	for(int i=25001,j=25000;i<=50000;i++,j--)
		ans[i]=-ans[j];

	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)printf("%d\n",ans[i]);
}