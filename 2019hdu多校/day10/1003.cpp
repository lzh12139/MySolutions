#include <bits/stdc++.h>
using namespace std;
typedef pair<double,double> pii;
#define ff first
#define ss second
#define ll long long
#define mp make_pair
#define pb emplace_back

double eps=1e-8;
double a[10010];
int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		scanf("%d",&n);
		for(int i=1; i<=n; i++) {
			scanf("%lf",&a[i]);
		}
		sort(a+1,a+1+n);
		double ans=a[n];
		for(int i=n; i>=1; i--)
			if(a[i]-0.5<eps) {
				double cmp=a[i];
				int d=i-1;
				while(cmp-0.5<eps&&d>=1) {
					cmp=cmp+a[d]-2.0*cmp*a[d];
					if(ans-cmp<eps)ans=cmp;
					d--;
				}
				break;
			}
		printf("%.12lf\n",ans);
	}
}
