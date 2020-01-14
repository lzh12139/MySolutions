#include<bits/stdc++.h>
using namespace std;
typedef pair<double,double> pii;
#define ff first
#define ss second

int n;
double y[1010],x1[1010],x2[1010];
double eps=1e-12,ans=1e18;
double mul(pii a,pii b){
    return a.ff*b.ss-a.ss*b.ff;
}
double len(pii a){
    return sqrt(a.ff*a.ff+a.ss*a.ss);
}
void dfs(int x,double cur,double curx,double cury){
    printf("%d %lf %lf %lf\n",x,cur,curx,cury);
    if(x>n){
        if(ans==1e18)ans=cur;
        else if(ans-cur>eps)ans=cur;
        return;
    }
    if(cur-ans>eps)return;

    if(x1[x]<=curx&&curx<=x2[x]){
        //printf("%lf %lf %lf\n",x1[x],curx,x2[x]);
        dfs(x+1,cur+cury-y[x],curx,y[x]);
    }

    pii l=make_pair(-1,0),r=make_pair(1,0);
    for(int i=x;i<=n;i++){
        if(mul(r,make_pair(x2[i]-curx,y[i]-cury))<0)r=make_pair(x2[i]-curx,y[i]-cury);
        if(mul(l,make_pair(x1[i]-curx,y[i]-cury))>0)l=make_pair(x1[i]-curx,y[i]-cury);

        if(mul(l,r)<0)return;
        //printf("l=%lf %lf r=%lf %lf\n",l.ff,l.ss,r.ff,r.ss);

        double t=(y[i]-cury)/l.ss;
        dfs(i+1,cur+len(l)*fabs(t),curx+l.ff*t,y[i]);

        t=(y[i]-cury)/r.ss;
        dfs(i+1,cur+len(r)*fabs(t),curx+r.ff*t,y[i]);
    }
}

int main(){
    while(scanf("%d",&n)&&n){
        double sx,sy;//scanf("%lf%lf",&sx,&sy);
        sx=0,sy=n;
        for(int i=1;i<=n;i++){
            //scanf("%lf%lf%lf",&y[i],&x1[i],&x2[i]);
            y[i]=n-i;
            x1[i]=rand()%200000,x2[i]=x1[i]+5;
        }

        ans=1e18;
        dfs(1,0,sx,sy);
        printf("%.11lf\n",ans);
    }
}