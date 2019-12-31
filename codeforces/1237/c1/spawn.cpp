#include<bits/stdc++.h>
#include<random>
using namespace std;
int main(){
    freopen("in.txt","w",stdout);
    //mt19937 rand(time(0));
    int T=2000,mod=1e8;
    printf("%d\n",T);
    for(int i=1;i<=T;i++)printf("%d %d %d\n",rand()%mod,rand()%mod,rand()%mod);
}