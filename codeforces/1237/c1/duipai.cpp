#include<bits/stdc++.h>
using namespace std;

int vis[2010];
int x[2010],y[2010],z[2010];
bool judge(int a,int b,int j,int c[]){
    return min(c[a],c[b])<=c[j]&&c[j]<=max(c[a],c[b]);
}
int main(){
    ifstream in("in.txt");
    ifstream ans("out.txt");
    int n;in>>n;
    for(int i=1;i<=n;i++)in>>x[i]>>y[i]>>z[i];
    for(int i=1;i<=n/2;i++){
        int a,b;ans>>a>>b;
        if(vis[a])cout<<"error:vis "<<a<<"\n";
        if(vis[b])cout<<"error:vis "<<b<<"\n";
        vis[a]=1,vis[b]=1;

        for(int j=1;j<=n;j++)
            if(!vis[j]&&judge(a,b,j,x)&&judge(a,b,j,y)&&judge(a,b,j,z)){
                cout<<"WA: "<<i<<"\n";
                cout<<x[a]<<" "<<y[a]<<" "<<z[a]<<"\n";
                cout<<x[b]<<" "<<y[b]<<" "<<z[b]<<"\n";
                cout<<x[j]<<" "<<y[j]<<" "<<z[j]<<"\n";
                cout<<"\n";
            }
    }
    cout<<"over";
}