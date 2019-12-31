/**
 * Author: hrynb
 * Time: 2019-10-16 21:47:54
**/

#include<bits/stdc++.h>
using namespace std;
#define mem(x, y) memset(x, (y), sizeof x)
#define ff first
#define ss second
#define mp(x, y) make_pair(x, y)
#define pb(x) emplace_back(x)
#define sc(a) scanf("%d", &a)
#define scl(a) scanf("%lld", &a)
#define scs(a) scanf("%s", a)
#define pr(a, b) printf("%d%c", a, b)
#define prl(a, b) printf("%ll%c", a, b)
#define all(v) v.begin(), v.end()
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define _yes printf("Yes\n")
#define _no printf("No\n")

typedef long long ll;
typedef vector<int> V;
typedef pair<int, int> pii;
typedef map<int, int> mii;

int a[100010];
int main(){
	int n;ll k;sc(n),scl(k);
	for(int i=1;i<=n;i++)sc(a[i]);
	sort(a+1,a+1+n);
	pii l=mp(0,0),r=mp(0,0);
	int curl,curr;
	for(int i=2;i<=n;i++)
		if(a[i]!=a[i-1]){
			l=mp(a[i-1],i-1),curl=i;
			break;
		}
	if(l.ss==0){
		printf("0");return 0;
	}
	for(int i=n-1;i>=1;i--)
		if(a[i]!=a[i+1]){
			r=mp(a[i+1],n-i),curr=i;
			break;
		}
	//printf("%d %d %d %d ",l.ff,l.ss,r.ff,r.ss);
	//printf("%d %d\n",curl,curr);
	while(l.ff!=r.ff){
		//printf("%d %d %d %d \n",l.ff,l.ss,r.ff,r.ss);
		if(l.ss<r.ss){
			k-=1ll*(a[curl]-a[curl-1])*l.ss;
			if(k<=0){
				k+=1ll*(a[curl]-a[curl-1])*l.ss;
				l.ff+=k/l.ss;
				break;
			}
			l.ff=a[curl],l.ss++,curl++;
		}
		else{
			k-=1ll*(a[curr+1]-a[curr])*r.ss;
			if(k<=0){
				k+=1ll*(a[curr+1]-a[curr])*r.ss;
				r.ff-=k/r.ss;
				break;
			}
			r.ff=a[curr],r.ss++,curr--;
		}
	}
	printf("%d\n",r.ff-l.ff);
}
