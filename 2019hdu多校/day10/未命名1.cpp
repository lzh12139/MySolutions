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
int main(){
    int t;scanf("%d",&t);
    while(t--){
        int n;scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%lf",&a[i]);
        }
        sort(a+1,a+1+n);
        double ans=a[n],ansn=a[n];
        int d=n-1;
        while(d>=1){
        	ans=ans+a[d]-2.0*ans*a[d],d--;
        	if(ansn-ans<eps)ansn=ans;
		}
		ans=a[1],d=2;
		while(d<=n){
			ans=ans+a[d]-2.0*ans*a[d],d++;
			if(ansn-ans<eps)ansn=ans;
		}
        printf("%.12lf\n",ansn);
    }
}
