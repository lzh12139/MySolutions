#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define ff first
#define ss second

const int N=1e7+6e6+10;
ll num[N],d;
ll quick_pow(ll base,ll b){
	ll res=1;
	while(b){
		if(b&1)res=res*base%d;
		base=base*base%d;
		b>>=1;
	}
	return res;
}
void cal(ll x,ll s){
	if(x<=d){
		num[1]+=s;num[d]-=s;
		return;
	}
	num[1]+=x/d*s,num[d]-=x/d*s;
	num[1]+=s,num[x%d+1]-=s;
	cal(x/d,s);
}
int main(){
	ll m,n;cin>>m>>n>>d;
	cal(m,1);
	cal(n,-1);
	cal(m-n,-1);

	ll fac=1,ans=0;
	for(int i=1;i<d;i++){
		num[i]+=num[i-1];
		fac=fac*i%d;
		ans+=quick_pow(fac,num[i]);
	}
	cout<<ans<<endl;
}