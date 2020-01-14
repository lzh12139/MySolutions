#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define ff first
#define ss second
int a[35][35],dd[4][2]={-1,0,1,0,0,-1,0,1},step[35][35];
pii hole[35][35];int holet[35][35],hole_step[35][35];
int w,h,can=1;
struct node{
    int x,y,t;
    node(int _x=0,int _y=0,int _t=0){
        x=_x,y=_y,t=_t;
    }
};
void bfs(int sx,int sy,int tt){
    memset(step,0,sizeof step);
    queue<node>q;
    q.push(node(sx,sy,tt)),step[sx][sy]=tt;
    while(!q.empty()){
        node x=q.front();q.pop();
        for(int i=0;i<4;i++){
            int dx=x.x+dd[i][0],dy=x.y+dd[i][1];

            if(dx<1||dy<1||dx>w||dy>h)continue;
            if(a[dx][dy]||step[dx][dy])continue;

            if(hole[dx][dy]!=make_pair(0,0)){
                if(x.t+holet[dx][dy]<0){
                    can=0;return;
                }
                step[dx][dy]=x.t+1;
                step[hole[dx][dy].ff][hole[dx][dy].ss]=x.t+1+holet[dx][dy];

                q.push(node(hole[dx][dy].ff,hole[dx][dy].ss,x.t+holet[dx][dy]));
            }
            else{
                step[dx][dy]=x.t+1;
                q.push(node(dx,dy,x.t+1));
            }
        }
    }
}
int main(){
    while(scanf("%d%d",&w,&h)&&w){
        memset(a,0,sizeof a);
        can=1;

        int n;scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int x,y;scanf("%d%d",&x,&y);
            a[x+1][y+1]=1;
        }
        scanf("%d",&n);
        pii zero=make_pair(0,0);
        for(int i=1;i<=w;i++)for(int j=1;j<=h;j++)hole[i][j]=zero;
        for(int i=1;i<=n;i++){
            int x,y,xx,yy,tt;scanf("%d%d%d%d%d",&x,&y,&xx,&yy,&tt);
            hole[x+1][y+1]=make_pair(xx+1,yy+1);
            holet[x+1][y+1]=tt;
        }

        bfs(1,1,1);
        for(int i=1;i<=w;i++)
            for(int j=1;j<=h;j++)
                printf("%d%c",step[i][j]," \n"[j==h]);
        int ans=step[w][h]-1;
        memset(hole_step,0,sizeof hole_step);
        
        for(int i=1;i<=w;i++)
            for(int j=1;j<=h;j++)
                if(hole[i][j]!=zero)hole_step[i][j]=step[i][j];

        for(int i=1;i<=w&&can;i++)
            for(int j=1;j<=h;j++)
                if(hole_step[i][j]){
                    bfs(i,j,hole_step[i][j]);

                    if(!can)break;
                }

        if(!can)printf("Never\n");
        else {
            if(ans==-1)printf("Impossible\n");
            else printf("%d\n",ans);
        }
    }
}