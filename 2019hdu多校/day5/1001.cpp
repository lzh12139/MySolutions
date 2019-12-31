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

vector<int>v[20000000];
int main() {
	int a[30],n=10,cnt=0;
	up(i,1,n)a[i]=i;
	do {
		cnt++;
		up(i,2,n)v[cnt].pb(a[i]-a[i-1]);
		up(i,1,n)v[cnt].pb(a[i]);
	} while(next_permutation(a+1,a+1+n));
	sort(v+1,v+1+cnt,[&](vector<int>a,vector<int>b) {
		up(i,0,n-2)
		if(a[i]<b[i])return true;
		else if(a[i]>b[i])return false;
	});
	printf("%d\n",cnt);
	int minn=10;
	up(i,1,10000)minn=min(minn,v[i][n-1]);printf("%d\n",minn);
	/*up(i,1,min(cnt,10000)) {
		for(auto i:v[i])printf("%2d ",i);
		printf("\n");
	}*/
}
