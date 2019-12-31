#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define ff first
#define ss second
#define mp make_pair
int a[100010],b[100010],x[100010],ans[100010];
#define DEBUG
int main(){
    srand(time(0));
    int n=1,l=10,r=20,k=2;//scanf("%d%d%d%d",&n,&l,&r,&k);
    //for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)a[i]=rand(),printf("%d ",a[i]);printf("\n");
    int cur=0,curn=1,minn=0,maxx=0;
    for(int i=2;i<=n;i++){
        if(a[i-1]<a[i])x[i]=1;
        else if(a[i-1]>a[i])x[i]=-1;
        else x[i]=0;
        cur+=x[i];
        if(cur<minn)minn=cur,curn=i;
        maxx=max(maxx,cur);
    }

#ifdef DEBUG
    printf("%d\n",curn);
    printf("%d %d\n",minn,maxx);
#endif
    /*if(maxx-minn>r-l){
        printf("-1");return 0;
    }*/

    pii p=mp(0,0);
    vector<pii>L,R;
    for(int i=curn;i>=2;i--)
        if(x[i]==0)continue;
        else if(x[i]==-1){
            if(p.ff==0)p.ss++;
            else {
                L.push_back(p);p=mp(0,1);
            }
        }
        else p.ff++;
    L.push_back(p);
    p=mp(0,0);
    for(int i=curn+1;i<=n;i++)
        if(x[i]==0)continue;
        else if(x[i]==1){
            if(p.ss==0)p.ff++;
            else{
                R.push_back(p);p=mp(1,0);
            }
        }
        else p.ss++;
    R.push_back(p);
    
#ifdef DEBUG
    printf("L:\n");
    for(auto i:L)printf("%d %d\n",i.ff,i.ss);
    printf("R:\n");
    for(auto i:R)printf("%d %d\n",i.ff,i.ss);
#endif

    ans[curn]=l;
    b[curn]=l;cur=l;
    int pre=curn;
    curn--;
    for(auto i:L){
        if(cur+i.ss-1ll*k*i.ff<l){
            // can to l
            int top=max(cur+i.ss,l+i.ff);
            int les=top-cur-i.ss;
            for(int j=1;j<=i.ss;j++,curn--)
                if(les>k-1){
                    b[curn]=cur+k;cur+=k;
                    les-=k-1;
                }
                else if(les){
                    b[curn]=cur+les+1;cur+=les+1;
                    les=0;
                }
                else {
                    b[curn]=cur+1;cur+=1;
                }
            les=top-l-i.ff;
            for(int j=1;j<=i.ff;j++,curn--)
                if(les>k-1){
                    b[curn]=cur-k;cur-=k;
                    les-=k-1;
                }
                else if(les){
                    b[curn]=cur-les-1;cur-=les+1;
                    les=0;
                }
                else {
                    b[curn]=cur-1;cur-=1;
                }
        }
        else {
            // can not to l
            for(int j=1;j<=i.ss;j++,curn--){
                b[curn]=cur+1;cur++;
            }
            for(int j=1;j<=i.ff;j++,curn--){
                b[curn]=cur-k;cur-=k;
            }
        }
    }
    cur=l;curn=pre+1;
    for(auto i:R){
        if(cur+i.ff-1ll*i.ss*k<l){
            // to l
            int top=max(cur+i.ff,l+i.ss);
            int les=top-cur-i.ff;
            for(int j=1;j<=i.ff;j++,curn++){
                if(les>k-1){
                    b[curn]=cur+k;cur+=k;
                    les-=k-1;
                }
                else if(les){
                    b[curn]=cur+les+1;cur+=les+1;
                    les=0;
                }
                else {
                    b[curn]=cur+1;cur++;
                }
            }
            les=top-l-i.ss;
            for(int j=1;j<=i.ss;j++,curn++){
                if(les>k-1){
                    b[curn]=cur-k;cur-=k;
                    les-=k-1;
                }
                else if(les){
                    b[curn]=cur-les-1;cur-=les+1;
                    les=0;
                }
                else {
                    b[curn]=cur-1;cur--;
                }
            }
        }
        else{
            // can not to l
            for(int j=1;j<=i.ff;j++,curn++){
                b[curn]=cur+1;cur++;
            }
            for(int j=1;j<=i.ss;j++,curn++){
                b[curn]=cur-k;cur-=k;
            }
        }
    }
    int cnt=pre-1;
    for(int i=pre-1;i>=1;i--)
        if(x[i+1]==0)ans[i]=ans[i+1];
        else ans[i]=b[cnt--];
    cnt=pre+1;
    for(int i=pre+1;i<=n;i++)
        if(x[i]==0)ans[i]=ans[i-1];
        else ans[i]=b[cnt++];
    for(int i=1;i<=n;i++)if(ans[i]<l||ans[i]>r){printf("-1");return 0;}
    for(int i=1;i<=n;i++)printf("%d ",ans[i]);
}