#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define ff first
#define ss second
 
int main(){
    int t;//scanf("%d",&t);
    t=100;
    while(t--){
        int k,l;//scanf("%d%d",&k,&l);
        k=rand()%1000000,l=1;
        if(l>=2000){
            printf("-1\n");continue;
        }
        ll ansx=-1,ansy,ansb;
        int len=3;
        for(int i=1;i*i<=k&&i<1000;i++)// x
            if(k%i==0){
                ll less=k/i,ok=0;
                //printf("less=%lld\n",less);
                for(ll j=less/2;j<=1000000;j++)// b
                    if((2*j-less)%(2*i+1)==0){
                        ll y=(2*j-less)/(2*i+1);
 
                        ll ac1=2*i+2,ac2=j-1ll*i*y;
                        ok=1;
                        //printf("%d %lld %lld\n",i,j,y);
                        while(ac1<=l){
                            ac2+=-1e6;
                            if(ac1*ac2>j+k){
                                ok=0;break;
                            }
                            ac1++;
                        }
 
                        ac1=2,ac2=j-y-1;
                        while(ac1<=2*i+1){
                            if(ac1*ac2>j+k){
                                ok=0;break;
                            }
                            if(ac1&1)ac2-=1+y;
                            else ac2++;
                            ac1++;
                        }
 
                        if(ok&&y+1<=1e6&&y>0){
                            ansx=i,ansy=y,ansb=j;
                            len=2*ansx+1;
                            break;
                        }
                    }
                if(ok)break;
            }
        if(ansx!=-1){
            printf("%d\n",max(len,l));
            for(int i=1;i<=ansx;i++)
                printf("%d %d ",1,-(1+ansy));
            printf("%d ",ansb);
            for(int i=2*ansx+2;i<=l;i++)
                printf("-100000 ");
            printf("\n");
        }
        else printf("-1\n");

        
    }
}
