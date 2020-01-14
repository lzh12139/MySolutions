#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define ff first
#define ss second

double a[100010],poww[100010],b[100010];
int main(){
    int l;double p,q;
    while(~scanf("%d%lf%lf",&l,&p,&q)){
        double ans=0,qless=1;
        poww[0]=1,poww[1]=1-q;
        for(int i=2;i<=l;i++)poww[i]=poww[i-1]*(1-q);

        for(int i=1;i<=l;i++)b[i]=2.0*i*(poww[i])*q,b[i]+=b[i-1];

        for(int i=0;i<l;i++){
            a[i]=b[l-i-1]+poww[l-i]*2*(l-i);
        }

        /*a[l]=0;
        for(int i=l-1;i>=0;i--){
            a[i]=a[i+1]+2*(l-i)*poww[l-i]*q;
        }*/
        for(int i=0;i<l;i++)ans+=1.0+p/(1-p)*a[i];

        printf("%.9Lf\n",ans);
    } 
}