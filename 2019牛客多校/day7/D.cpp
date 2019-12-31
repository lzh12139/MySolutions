#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define ff first
#define ss second
#define ll long long
#define mp make_pair
#define pb emplace_back

int main(){
	int n,p;scanf("%d%d",&n,&p);
	int gg=p,c=0;
	while(gg){
		c++,gg/=10;
	}
	if(c>n)printf("T_T\n");
	else {
		printf("%d",p);
		for(int i=c+1;i<=n;i++)printf("0");
		printf("\n");
	}
}
