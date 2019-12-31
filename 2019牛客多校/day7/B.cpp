#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define ff first
#define ss second
#define ll long long
#define mp make_pair
#define pb emplace_back

int a[50];
int main(){
	int t;scanf("%d",&t);
	while(t--){
		int n;scanf("%d",&n);
		for(int i=n;i>=0;i--)scanf("%d",a+i);
		if(n>2)printf("No\n");
		else{
			if(n==2){
				if(1ll*a[1]*a[1]-4ll*a[0]*a[2]>=0)printf("No\n");
				else printf("Yes\n");
			}
			else if(n==1){
                printf("Yes\n");
			}
			else printf("Yes\n");
		}
	}
}
