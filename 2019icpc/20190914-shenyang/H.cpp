#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define ff first
#define ss second
#define mp make_pair
#define pb emplace_back

struct node{
	string name;
	int cnt[15],n;
	pii p[8];
	node(){
		n=0;
		memset(cnt,0,sizeof cnt);
	}
	bool operator<(const node &b)const{
		for(int i=1;i<=min(n,b.n);i++)
			if(p[i].ff!=b.p[i].ff)return p[i].ff>b.p[i].ff;
       		else if(p[i].ss!=b.p[i].ss)return p[i].ss>b.p[i].ss;
		if(n==b.n)return name<b.name;
		return n>b.n;
	}
	void getvalue(){
		if(cnt[1]&&cnt[10]&&cnt[11]&&cnt[12]&&cnt[13]){
			p[++n]=mp(8,0);return;
		}
		for(int i=1;i<=9;i++)
			if(cnt[i]&&cnt[i+1]&&cnt[i+2]&&cnt[i+3]&&cnt[i+4]){
				p[++n]=mp(7,i+4);return;
			}
		for(int i=1;i<=13;i++)
			if(cnt[i]==4){
				int less=0;
				for(int o=1;o<=13;o++)if(cnt[o]==1){less=o;break;}
				p[++n]=mp(6,i),p[++n]=mp(1,less);return;
			}
		for(int i=1;i<=13;i++)
			if(cnt[i]==3){
				int pairr=0,add=0;
				for(int o=1;o<=13;o++)if(cnt[o]==2)pairr=o;
                for(int o=1;o<=13;o++)if(cnt[o]==1)add+=o;
				if(pairr)p[++n]=mp(5,i),p[++n]=mp(2,pairr);
				else p[++n]=mp(4,i),p[++n]=mp(1,add);
				return;
			}
		for(int i=1;i<=13;i++)
			if(cnt[i]==2){
				for(int o=1;o<=13;o++)
					if(cnt[o]==2&&i!=o)
						for(int j=1;j<=13;j++)
							if(cnt[j]==1){
								p[++n]=mp(3,max(i,o)),p[++n]=mp(3,min(i,o));
								p[++n]=mp(1,j);
								return;
							}
				int add=0;
				for(int o=1;o<=13;o++)if(cnt[o]==1)add+=o;
				p[++n]=mp(2,i),p[++n]=mp(1,add);
				return;
			}
		int add=0;
		for(int i=1;i<=13;i++)if(cnt[i])add+=i;
		p[++n]=mp(1,add);return;
	}
};
node p[100010];
int main(){
	//ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i].name;
		string s;cin>>s;
		for(int o=0;o<s.length();o++){
			if(s[o]>='2'&&s[o]<='9')p[i].cnt[s[o]-'0']++;
			else if(s[o]=='A')p[i].cnt[1]++;
			else if(s[o]=='J')p[i].cnt[11]++;
			else if(s[o]=='Q')p[i].cnt[12]++;
			else if(s[o]=='K')p[i].cnt[13]++;
			else if(s[o]=='1')p[i].cnt[10]++,o++;
		}
		p[i].getvalue();
		//for(int o=1;o<=13;o++)printf("%d ",p[i].cnt[o]);printf("\n");
		//for(int o=1;o<=p[i].n;o++)printf("%d %d\n",p[i].p[o].ff,p[i].p[o].ss);
	}
	sort(p+1,p+1+n);
	for(int i=1;i<=n;i++)cout<<p[i].name<<"\n";
}
/*
8
A AKJQ10
B 45678
C 33334
D 55577
E 66689
F JJQQ2
G KK234
H 96352
*/