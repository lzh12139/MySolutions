#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define ff first
#define ss second
#define ll long long
#define mp make_pair
#define pb emplace_back
#define ull unsigned long long

ull a[50],b[50];
pair<ull,int> l[1<<20];
pair<ull,int> r[1<<20];
int out(int x,int n) {
	for(int i=1; i<=n; i++) {
		if(x&1)printf("1");
		else printf("0");
		x>>=1;
	}
}
int main() {
	ull n,sum;
	cin>>n>>sum;
	for(int i=1; i<=n/2; i++)cin>>a[i];
	for(int i=1; i<=n-n/2; i++)cin>>b[i];
	int linf=(1<<(n/2))-1;
	for(int i=1; i<=linf; i++) {
		int cmp=i,c=1;
		l[i].ss=i;
		while(cmp) {
			if(cmp&1)l[i].ff+=a[c];
			++c,cmp>>=1;
		}
		if(l[i].ff==sum) {
			out(i,n/2);
			out(0,n-n/2);
			return 0;
		}
	}
	sort(l+1,l+linf);
	int rinf=(1<<(n-n/2))-1;
	for(int i=1; i<=rinf; i++) {
		int cmp=i,c=1;
		r[i].ss=i;
		while(cmp) {
			if(cmp&1)r[i].ff+=b[c];
			++c,cmp>>=1;
		}
		if(r[i].ff==sum) {
			out(0,n/2);
			out(i,n-n/2);
			return 0;
		}
	}
	sort(r+1,r+rinf);

	int li=1,ri=rinf;
	while(li<=linf&&ri>0) {
		if(l[li].ff+r[ri].ff==sum) {
			out(l[li].ss,n/2);
			out(r[ri].ss,n-n/2);
			return 0;
		} else if(l[li].ff+r[ri].ff>sum)ri--;
		else li++;
	}

	li=linf,ri=1;
	while(li>0&&ri<=rinf) {
		if(l[li].ff+r[ri].ff==sum) {
			out(l[li].ss,n/2);
			out(r[ri].ss,n-n/2);
			return 0;
		} else if(l[li].ff+r[ri].ff>sum)li--;
		else ri++;
	}
}
