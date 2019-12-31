#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("1.out","r",stdin);
    double pre=2;
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x;scanf("%d",&x);
        if(pre>sin(x))pre=sin(x);
        else{
            printf("NO:%d\n",i);
            printf("%.12lf %d %.12lf\n",pre,x,sin(x));
            break;
        }
    }
    printf("YES\n");
}