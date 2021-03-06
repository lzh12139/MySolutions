#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define ff first
#define ss second

struct FastIO {
	static const int LEN=1<<18|1;
	char buf[LEN],wbuf[LEN];
	int s=0,t=0,wpos=0;
	inline int read(){
        int res=((s==t)&&(t=(s=0)+fread(buf,1,LEN,stdin)),s==t?-1:buf[s++]);
        if(res==EOF)exit(0);
		return res;
	}
	inline void out(int x){
		wpos==LEN?fwrite(wbuf,1,LEN,stdout),wpos=0:wbuf[wpos++]=x;
	}
	// 有符号：
	inline int rint(){
		// 根据读入是int还是long long决定x的类型
		int c=read(),x=0,s=1;
		if(c==-1)return 0;
		while(c<=32)c=read();
		if(c=='-')s=-1,c=read();
		while(isdigit(c))x=x*10+c-'0',c=read();
		return x*s;
	}
	inline int ruint(){
		int c=read(),x=0;
		while(c<=32)c=read();
		while(isdigit(c))x=x*10+c-'0',c=read();
		return x;
	}
	inline void rstr(char *str){
		int c=read();
		while(c<=32)c=read();
		while(c>32)*str++=c,c=getchar();
		*str=0;
	}
	// 根据类型
	inline void wint(long long x){
		// 如果含有负数，取消注释
		// if(x<0)wchar('-'),x=-x;
		char str[24];int n=0;
		while(x||!n)str[n++]='0'+x%10,x/=10;
		while(n--)out(str[n]);
	}
	inline void wchar(char str){
		out(str);
	}
	inline void wstr(const char *s){
		while(*s)out(*s++);
	}
	inline void over(){
		if(wpos)fwrite(wbuf,1,wpos,stdout),wpos=0;
	}
	~FastIO(){
		if(wpos)fwrite(wbuf,1,wpos,stdout),wpos=0;
	}
}io;

int a[1010],b[1010],vis[3010];
int main(){
    int n,m;
    while(1){
        n=io.ruint(),m=io.ruint();
        for(int i=1;i<=1000;i++)vis[i]=0;
        for(int i=1;i<=n;i++)a[i]=io.ruint(),vis[a[i]]++;
        for(int i=1;i<=m;i++)b[i]=io.ruint();

        for(int i=0;i<=1010;i++){
            int ok=1;
            for(int j=1;j<=m;j++)
                if(vis[b[j]+i]){ok=0;break;}

            if(ok){
                io.wint(i),io.wchar('\n');
                break;
            }
        }
    }
}