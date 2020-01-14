#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define ff first
#define ss second

struct node{
	int x,y,val;
	node(int _x=0,int _y=0,int _val=0){
		x=_x,y=_y,val=_val;
	}
	bool operator<(const node &b)const{
		node tmp1=*this,tmp2=b;
		if(tmp1.x<0)tmp1=node(-tmp1.x,-tmp1.y,tmp1.val);
		if(tmp2.x<0)tmp2=node(-tmp2.x,-tmp2.y,tmp1.val);

		return 1ll*tmp1.y*tmp2.x<1ll*tmp1.x*tmp2.y;
	}
};
node yuan[4010],a[4010];

int main(){
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d%d",&yuan[i].x,&yuan[i].y,&yuan[i].val);

	ll ans=1e18;
	for(int i=1;i<=n;i++){
		int cnt=0,need_cal=0,is_up=0;
		ll vall=0,valr=0;
		for(int j=1;j<=n;j++)
			if(i!=j){
				a[++cnt]=node(yuan[j].x-yuan[i].x,yuan[j].y-yuan[i].y,yuan[j].val);

				if(yuan[j].x<yuan[i].x)vall+=yuan[j].val;
				else if(yuan[j].x>yuan[i].x)valr+=yuan[j].val;
				else {
					need_cal=yuan[j].val;cnt--;
					if(yuan[j].y>yuan[i].y)is_up=1;
				}
			}
		a[0]=node(0,0,0);
		if(need_cal){
			ans=min(ans,abs(vall-valr));
			if(is_up)a[0]=node(-1e9-10,0,need_cal);
			else a[0]=node(1e9+10,0,need_cal);
		}
		sort(a+1,a+1+cnt);
		/*cerr<<"------\n"<<a[0].x<<" "<<a[0].y<<" "<<a[0].val<<endl;
		cerr<<vall<<" "<<valr<<endl;
		for(int j=1;j<=cnt;j++)cerr<<a[j].x<<" "<<a[j].y<<" "<<a[j].val<<endl;
		cerr<<"-----------------\n";*/

		for(int j=1;j<=cnt;j++){
			if(a[j-1].x<0)valr+=a[j-1].val;
			else vall+=a[j-1].val;
			if(a[j].x<0)vall-=a[j].val;
			else valr-=a[j].val;

			//cerr<<j<<" "<<vall<<" "<<valr<<endl;
			//if(abs(vall-valr)==0)cerr<<"^^^^^^^^^^^^^^^\n";

			ans=min(ans,abs(vall-valr));
		}
	}
	printf("%lld\n",ans);
}