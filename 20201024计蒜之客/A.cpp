#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define ll long long

int main(){
    int n,m,cnt=0;cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        if(x==1)cnt++;
    }
    if(cnt>=2)cout<<"2";
    else cout<<"3";
}