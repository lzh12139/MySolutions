#include <bits/stdc++.h>
using namespace std;
char ch[1001];
string str;
string ans;
bool flag;
bool check(int l,int r){
    while (l<r && (str[l]==str[r] || str[l]=='?' || str[r]=='?') && str[l]!='*' && str[r]!='*') {
        l++; r--;
    }
    if (l>=r || str[l]=='*' || str[r]=='*') return true;
    return false;
}
void solve(int l,int r){
    if (l>r) return;
    if (l==r){
        if (str[l]!='*'){
            if (str[l]=='?') ans+='a';
            else ans+=str[l];
        }
        return;
    }
    if (str[l]=='*' && str[r]=='*'){
        solve(l,r-1);
    } else if (str[l]=='*'){
        for (int i=0;i<=r-l-1;++i){
            //cout<<str.substr(l+1,r-i);
            if (check(l+1,r-i)){
                solve(l+1,r-i);
                for (int j=r-i+1;j<=r;++j){
                    char ch='a';
                    if (str[j]!='?') ch=str[j];
                    ans=ch+ans+ch;
                }
                return;
            }
        }
        flag=false;
        return;
    } else if (str[r]=='*'){
        for (int i=0;i<=r-l-1;++i){
            //cout<<str.substr(l+1,r-i);
            if (check(l+i,r-1)){
                solve(l+i,r-1);
                for (int j=l+i-1;j>=l;--j){
                    char ch='a';
                    if (str[j]!='?') ch=str[j];
                    ans=ch+ans+ch;
                }
                return;
            }
        }
        flag=false;
        return;
    }else {
        if (str[l]=='?' || str[r]=='?' || str[l]==str[r]){
            solve(l+1,r-1);
            char ch='a';
            if (str[l]!='?') ch=str[l];
            if (str[r]!='?') ch=str[r];
            ans=ch+ans+ch;
        } else {
            flag=false;
            return;
        }
    }
}
int main(){
    scanf("%s",ch);
    int len=strlen(ch);
    str=ch;
    ans.clear();
    flag=true;
    solve(0,len-1);
    if (flag){
        if (ans.size()==0) ans='a';
        printf("%s",ans.c_str());
    } else printf("-1");
}