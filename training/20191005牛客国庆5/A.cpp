#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char s1[50],s2[50];
typedef unsigned long long ull;
typedef pair<ull,int> pii;
#define ff first
#define ss second
#define mp make_pair

pii solve(char s[]){
    int len=strlen(s+1);
    int st=1,f=1;
    if(s[st]=='-')st++,f=-1;
    ull res=0;
    for(int i=st;i<=len;i++)res=res*10+s[i]-'0';
    return mp(res,f);
}

int main(){
    while(cin>>s1+1>>s2+1){
        pii x=solve(s1),y=solve(s2);
        ull ans=x.ff/y.ff;
        if(x.ss*y.ss==-1){
            cout<<"-";
            if(x.ff%y.ff)ans++;
        }
        cout<<ans<<"\n";
   }
}