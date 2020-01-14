#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define ff first
#define ss second

int a[5000];
int main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    ll ans=0;
    for(int i=1;i<=n;i++){
        ll sum=0;
        for(int j=i;j<=n;j++){
            sum+=a[j];
            ans=max(ans,sum*(j-i+1));
        }
    }
    cout<<ans<<endl;
}