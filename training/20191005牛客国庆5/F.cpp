#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int a,b,c;
    while(~scanf("%d%d%d",&a,&b,&c)){
        if(b*b-4*a*c<=0&&a>=0&&c>=0)printf("Yes\n");
        else printf("No\n");
    }
}