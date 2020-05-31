#include <bits/stdc++.h>
using namespace std;
int a[200001];
int b[200001];
int tmp[200001];
struct Answer{
    int op,l,r;
    Answer(int _op,int _l,int _r){op=_op; l=_l; r=_r;}
    Answer(){}
};
vector<Answer> solve(int n,int st,int ed,int dt,bool &f){
    vector<Answer> ans;
    memcpy(tmp,a,sizeof(tmp));
    int Min=tmp[st],Max=tmp[ed];
    int j=st;
    for (int i=st;i!=ed;i+=dt){
        if (j>=i) tmp[i]=Min;
        if (tmp[i]==b[i]) continue;
        if (i>0 && b[i]==tmp[i-1]){
            ans.push_back(Answer(0,i-1,i));
            tmp[i]=b[i];
            continue;
        }
        while (j>=0 && j<n && b[i]!=tmp[j]){
            Min=min(Min,tmp[j]); Max=max(Max,tmp[j]);
            j+=dt;
        }
        if (j>=n || j<0){ f=false; return ans;}
        if (Min==b[i]) ans.push_back(Answer(0,i,j));
        else if (Max==b[i]) ans.push_back(Answer(1,i,j));
        else {
            ans.push_back(Answer(0,i,j-1));
            ans.push_back(Answer(1,i,j));
            Min=Max=b[i];
        }
        tmp[i]=b[i];
    }
    f=true;
    return ans;
}
void out(vector<Answer> &ans){
    printf("%d\n",ans.size());
    for (auto answer:ans){
        if (answer.op==0) putchar('m');
        else putchar('M');
        printf(" %d %d\n",answer.l+1,answer.r+1);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;++i) scanf("%d",&a[i]);
    for (int i=0;i<n;++i) scanf("%d",&b[i]);
    bool f1,f2;
    vector<Answer> ans1=solve(n,0,n,1,f1);
    vector<Answer> ans2=solve(n,n-1,-1,-1,f2);
    if (f1) out(ans1);
    else if (f2) out(ans2);
    else printf("-1\n");
}