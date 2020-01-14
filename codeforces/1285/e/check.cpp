#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define mp(x, y) make_pair(x, y)
#define pb(x) emplace_back(x)
#define _yes printf("Yes\n")
#define _no printf("No\n")

typedef long long ll;
typedef vector<int> V;
typedef pair<int, int> pii;

int main(){
    auto in1=fopen("ans3.txt","r"),in2=fopen("out.txt","r");
    for(int i=1;i<=1000;i++){
        int a,b;
        fscanf(in1,"%d",&a);
        fscanf(in2,"%d",&b);
        if(a!=b)printf("%d\n",i);
    }
}