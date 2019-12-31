#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define ff first
#define ss second
#define ll long long
#define mp make_pair
#define pb emplace_back

ll cnt[20];

int main(){
	for(int i=1;i<=1234;i++){
		int cmp=i;
		while(cmp){
			cnt[cmp%10]++;
			cmp/=10;
		}
	}
	for(int i=0;i<=9;i++)printf("%d ",cnt[i]);
}
