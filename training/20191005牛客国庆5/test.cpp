#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[100],n=0,cnt=0;
    int cnta=1,cntb=1,cntc=3;
    scanf("%d%d%d",&cnta,&cntb,&cntc);
    int wina=0,winb=0,winc=0;
    n=cnta+cntb+cntc;
    for(int i=1;i<=n;i++)a[i]=i;
    do{
        int j=0,k=0,l=0;
        for(int i=1;i<=n;i++){
            if(a[i]<=cnta)j++;
            else if(a[i]<=cnta+cntb)k++;
            else l++;
            if(j==cnta){wina++;break;}
            else if(k==cntb){winb++;break;}
            else if(l==cntc){winc++;break;}
        }
        cnt++;
    }while(next_permutation(a+1,a+1+n));
    printf("%d\n",cnt);
    printf("%d %d %d\n",wina,winb,winc);
    int g=__gcd(cnt,wina);printf("%d/%d ",wina/g,cnt/g);
    g=__gcd(cnt,winb);printf("%d/%d ",winb/g,cnt/g);
    g=__gcd(cnt,winc);printf("%d/%d ",winc/g,cnt/g);
}