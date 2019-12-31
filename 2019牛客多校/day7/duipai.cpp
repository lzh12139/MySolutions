#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define ff first
#define ss second
#define ll long long
#define mp make_pair
#define pb emplace_back

int main(){
	srand((unsigned)time(NULL));
	freopen("in.txt","w",stdout);
	printf("300\n");
	for(int t=1;t<=100;t++){
		for(int i=1;i<=50;i++)printf("%d",rand()&1);
		printf("\n");
	}
	
}
