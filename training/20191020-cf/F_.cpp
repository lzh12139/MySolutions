#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using ll=long long;
#define ff first
#define ss second
#define mp make_pair

struct node{
	int same,x,y;
	node(){}
	node(int _s,int _x,int _y):same(_s),x(_x),y(_y){}
};

vector<node>r,c;

int main() {
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int aa,bb,cc,dd;scanf("%d%d%d%d",&aa,&bb,&cc,&dd);
		if(aa>cc)swap(aa,cc);
		if(bb>dd)swap(bb,dd);
		if(aa==cc)c.push_back(node(aa,bb,dd));
		else r.push_back(node(bb,aa,cc));
	}
	int p;scanf("%d",&p);
	pii p1,p2;scanf("%d%d%d%d",&p1.ff,&p1.ss,&p2.ff,&p2.ss);
	ll S=1ll*(p2.ff-p1.ff)*(p2.ss-p1.ss);

	int l=1,r=1e5;
	while(l<=r){
		int mid=l+r>>1;

		int rmin=p1.ss,rmax=p2.ss,cmin=p1.ff,cmax=p2.ff;
		for(auto i:c){
			rmin=max
		}
	}
}
