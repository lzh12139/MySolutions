#include<bits/stdc++.h>
using namespace std;
typedef pair<double,double> pii;
#define ff first
#define ss second

int main(){
    int n;
    while(scanf("%d",&n)&&n){
        int D=0,T=0;
        for(int i=1;i<=n;i++){
            char s[10];int x;
            scanf("%s%d",s+1,&x);
            if(s[1]=='D'){
                D+=x;
                printf("DROP 2 %d\n",x);
            }
            else{
                if(T>=x){
                    printf("TAKE 1 %d\n",x);
                    T-=x;
                }
                else {
                    if(T){
                        printf("TAKE 1 %d\n",T);
                        x-=T;
                        T=0;
                    }

                    printf("MOVE 2->1 %d\n",D);
                    T=T+D;
                    D=0;

                    printf("TAKE 1 %d\n",x);
                    T-=x;
                }
            }
        }
        printf("\n");
    }
}