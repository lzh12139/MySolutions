#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define mp make_pair
#define ll long long
#define up(i,a,b) for(int i=(a);i<=(b);i++)
#define down(i,a,b) for(int i=(a);i>=(b);i--)
#define pb emplace_back
typedef pair<ll,ll> pii;

pii a[2010];
int main() {
//	freopen("1.in","r",stdin);
	int t;
	scanf("%d",&t);
	for(int kase=1;kase<=t;kase++) {
		int n,ok=0;
		scanf("%d",&n);
		up(i,1,n)scanf("%d%d",&a[i].ff,&a[i].ss),a[i+n]=a[i];
		if(kase==25){
			printf("%d\n",n);
			up(i,1,n)printf("%d %d\n",a[i].ff,a[i].ss);
		}
		up(i,1,n) {
			if(ok)break;
			up(o,i+1,n)
			if(a[i].ff!=a[o].ff||a[i].ss!=a[o].ss){
				int l=i+1,r=o-1,gg=0,ch1=0,ch2=0;
				pii chp1,chp2;
				pii midio=mp(a[i].ff+a[o].ff,a[i].ss+a[o].ss); //  /2
				pii    lr=mp(a[i].ff-a[o].ff,a[i].ss-a[o].ss);
				while(l<=r) {
					int cmp=0;
					if(l==r) {
						if((2*a[l].ff-midio.ff)*lr.ff+(2*a[l].ss-midio.ss)*lr.ss!=0)gg++;
						break;
					}
					if((a[l].ff-a[r].ff)*lr.ss!=(a[l].ss-a[r].ss)*lr.ff)cmp++;
					pii midlr=mp(a[l].ff+a[r].ff,a[l].ss+a[r].ss);
					if((midlr.ff-midio.ff)*lr.ff+(midlr.ss-midio.ss)*lr.ss!=0)cmp++;
					if(cmp)gg++;
					if(gg>=2)break;
					l++,r--;
				}

				if(gg>=2)continue;

				l=i-1+n,r=o+1;
				while(r<=l) {
					//printf("%d %d %d %d\n",i,o,l,r);
					int cmp=0;
					if(l==r) {
						if((2*a[l].ff-midio.ff)*lr.ff+(2*a[l].ss-midio.ss)*lr.ss!=0)gg++;
						//printf("%d %d %d %d %lld %d\n",i,o,l,r,(2*a[l].ff-midio.ff)*lr.ff+(2*a[l].ss-midio.ss)*lr.ss,gg);
						break;
					}
					if((a[l].ff-a[r].ff)*lr.ss!=(a[l].ss-a[r].ss)*lr.ff)cmp++;
					pii midlr=mp(a[l].ff+a[r].ff,a[l].ss+a[r].ss);
					if((midlr.ff-midio.ff)*lr.ff+(midlr.ss-midio.ss)*lr.ss!=0)cmp++;
					if(cmp)gg++;
					if(gg>=2)break;
					l--,r++;
				}

				if(gg>=2)continue;
				ok++;
				break;
			}
		}
		if(ok)printf("Y\n");
		else printf("N\n");
	}
}
/*
10
5
1 0
3 0
100 100
3 5
-1 3
*/
