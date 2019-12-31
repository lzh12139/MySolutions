#include<bits/stdc++.h>
using namespace std;
int r[100010],c[100010];
#define _yes printf("YES\n");continue;
#define _no printf("NO\n");continue;
int main(){
	int n,q;scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&r[i]);r[i]&=1;r[i]+=r[i-1];
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);c[i]&=1;c[i]+=c[i-1];
	}
	while(q--){
		int x1,y1,x2,y2;scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if(x1==x2){
			if(y1>y2)swap(y1,y2);
			if(r[x1]-r[x1-1]==1&&c[y2-1]-c[y1]==y2-y1-1){_yes;}
			if(r[x1]-r[x1-1]==0&&c[y2-1]-c[y1]==0){_yes;}
			_no;
		}
		if(y1==y2){
			if(x1>x2)swap(x1,x2);
			if(c[y1]-c[y1-1]==1&&r[x2-1]-r[x1]==x2-x1-1){_yes;}
			if(c[y1]-c[y1-1]==0&&r[x2-1]-r[x1]==0){_yes;}
			_no;
		}
		if(x1>x2)swap(x1,x2),swap(y1,y2);
		if(y1<y2){
			if(c[y1]-c[y1-1]==1&&r[x2]-r[x1]==x2-x1
				&&r[x2]-r[x2-1]==1&&c[y2-1]-c[y1]==y2-y1-1){_yes;}
			if(c[y1]-c[y1-1]==0&&r[x2]-r[x1]==0
				&&r[x2]-r[x2-1]==0&&c[y2-1]-c[y1]==0){_yes;}
			if(r[x1]-r[x1-1]==1&&c[y2]-c[y1]==y2-y1
				&&c[y2]-c[y2-1]==1&&r[x2-1]-r[x1]==x2-x1-1){_yes;}
			if(r[x1]-r[x1-1]==0&&c[y2]-c[y1]==0
				&&c[y2]-c[y2-1]==0&&r[x2-1]-r[x1]==0){_yes;}
			_no;
		}
		else{
			if(c[y1]-c[y1-1]==1&&r[x2]-r[x1]==x2-x1
				&&r[x2]-r[x2-1]==1&&c[y1-1]-c[y2]==y1-y2-1){_yes;}
			if(c[y1]-c[y1-1]==0&&r[x2]-r[x1]==0
				&&r[x2]-r[x2-1]==0&&c[y1-1]-c[y2]==0){_yes;}
			if(r[x1]-r[x1-1]==1&&c[y1]-c[y2]==y1-y2
				&&c[y2]-c[y2-1]==1&&r[x2-1]-r[x1]==x2-x1-1){_yes;}
			if(r[x1]-r[x1-1]==0&&c[y2]-c[y1]==0
				&&c[y2]-c[y2-1]==0&&r[x2-1]-r[x1]==0){_yes;}
			_no;
		}
	}
}