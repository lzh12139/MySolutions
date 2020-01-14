#include<bits/stdc++.h>
using namespace std;
struct FastIO {
	static const int LEN=1<<18|1;
	char buf[LEN],wbuf[LEN];
	int s=0,t=0,wpos=0;
	inline int read(){
		return (s==t)&&(t=(s=0)+fread(buf,1,LEN,stdin)),s==t?-1:buf[s++];
	}
	inline void out(int x){
		wpos==LEN?fwrite(wbuf,1,LEN,stdout),wbuf[0]=x,wpos=1:wbuf[wpos++]=x;
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
	inline void wint(int x){
		// 如果含有负数，取消注释
		if(x<0)wchar('-'),x=-x;
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
 
int li[]={6,28,496,8128};
int len=4;
 
int main(){
    int n=io.rint();
    while (n--){
        int k=io.rint();
        int ans;
        for (ans=len-1;ans>=0;--ans)
            if (li[ans]<=k) break;
        if (ans<0) io.wint(-1);
        else io.wint(li[ans]);
        io.wchar('\n');
    }
}