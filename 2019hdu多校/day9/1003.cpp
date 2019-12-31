#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define ff first
#define ss second
#define ll long long
#define mp make_pair
#define pb emplace_back

ll a[44];
vector<ll> vl[12][12],vr[12][12];
int dd [2][11]= {{0,0,1,2,3,4,5,6,7,8,9},{0,4,3,2,1,0,9,8,7,6,5}};// 1-5,6-10
int dd3[2][11]= {{0,0,1,2,3,4,5,6,7,8,9},{0,3,2,1,0,9,8,7,6,5,4}};// 1-4,5-10
ll jinwei[20];
int main() {
	jinwei[1]=10;
	for(int i=2; i<=15; i++)jinwei[i]=jinwei[i-1]*10;
	int t;
	scanf("%d",&t);
	while(t--) {
		for(int i=0; i<=11; i++)for(int o=0; o<=9; o++)vl[i][o].clear(),vr[i][o].clear();
		int n;
		ll ans=0;
		scanf("%d",&n);
		for(int i=1; i<=n; i++)scanf("%lld",&a[i]);
		int l=n/2,r=n-n/2;
		for(int i=(1<<l)-1; i>=1; i--) {
			int c=i,cnt=1;
			ll cmp=0;
			while(c) {
				if(c&1)cmp+=a[cnt];
				cnt++,c>>=1;
			}
			ll kmp=cmp,add=10;
			int wei=1;
			while(kmp) {
				if(kmp%10==4)ans++;
				vl[wei-1][kmp%10].pb(cmp%add);
				kmp/=10,add*=10,wei++;
			}
		}
		for(int i=(1<<r)-1; i>=1; i--) {
			int c=i,cnt=l+1;
			ll cmp=0;
			while(c) {
				if(c&1)cmp+=a[cnt];
				cnt++,c>>=1;
			}
			ll kmp=cmp,add=10;
			int wei=1;
			while(kmp) {
				if(kmp%10==4)ans++;
				vr[wei-1][kmp%10].pb(cmp%add);
				kmp/=10,add*=10,wei++;
			}
		}

		for(int i=1; i<=10; i++)for(int o=0; o<=9; o++)
				sort(vl[i][o].begin(),vl[i][o].end()),sort(vr[i][o].begin(),vr[i][o].end());

		for(int i=1;i<=2;i++)
		for(int o=0;o<=9;o++){
			printf("i=%d o=%d: ",i,o);
			printf("vl: ");for(auto i:vl[i][o])printf("%lld ",i);
			printf("vr: ");for(auto i:vr[i][o])printf("%lld ",i);
			printf("\n");
		}

		//for(int i=1; i<=10; i++)
		//	ans+=1ll*vl[0][dd[0][i]].size()*vr[0][dd[1][i]].size();

		for(int wei=0; wei<10; wei++) {
			for(int i=1; i<=10; i++) {
				// vl[wei][dd[0][i]]+vr[wei][dd[1][i]]<jinwei[wei];
				int right=vr[wei][dd[1][i]].size()-1,left=0;
				for(auto o:vl[wei][dd[0][i]]) {
					while(right>=0&&o+vr[wei][dd[1][i]][right]>=jinwei[wei])right--;
					printf("%d %d %d %d\n",wei,i,left,right);
					ans+=right-left+1;
					left++;
				}
			}

			if(wei)
				for(int i=1; i<=10; i++) {
					// vl[wei][dd[0][i]]+vr[wei][dd[1][i]]>=jinwei[wei];
					int right=vr[wei][dd3[1][i]].size()-1,sz=vr[wei][dd3[1][i]].size();
					for(auto o:vl[wei][dd3[0][i]]) {
						while(right>=0&&o+vr[wei][dd3[1][i]][right]<jinwei[wei])right--;
						ans+=sz-right-1;
					}
				}
		}
		printf("%lld\n",ans);
	}

}
