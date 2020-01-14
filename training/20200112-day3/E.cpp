#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define ff first
#define ss second

char s[10010][30];
int a[10010];
int main(){
	int n,num=0,numzero=0,sum=0;scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s%d",s[i],&a[i]);
		if(a[i])num++;
		else numzero++;
		sum+=a[i];
	}
	sum*=100;

	int ansl=200,ansr=-100,anszl=200,anszr=-100;

	for(int l=-50;l<=49;l++)
		for(int r=l;r<=49;r++){
			int zl=max(0,l),zr=r;
			if(num){
				if(sum+l+(num-1)*r+numzero*zr>=10000){
					//if(r==49&&zr==49)
					//printf("1 %d %d %d %d %d\n",l,r,zl,zr,sum+l+(num-1)*r+numzero*zr);
					ansl=min(ansl,l);
					ansr=max(ansr,r);
					//anszl=min(anszl,zl);
					anszr=max(anszr,zr);
				}
				if(sum+r+(num-1)*l+numzero*zl>=10000){
					//if(r==49&&zr==49)
					//printf("2 %d %d %d %d %d\n",l,r,zl,zr,sum+r+(num-1)*l+numzero*zl);
					ansl=min(ansl,l);
					ansr=max(ansr,r);
					anszl=min(anszl,zl);
					//anszr=max(anszr,zr);
				}
			}
			if(numzero){
				if(sum+num*r+zl+(numzero-1)*zr>=10000){
					//if(r==49&&zr==49&&l==49)
					//printf("3 %d %d %d %d %d\n",l,r,zl,zr,sum+num*r+zl+(numzero-1)*zr);
					//ansl=min(ansl,l);
					ansr=max(ansr,r);
					anszl=min(anszl,zl);
					anszr=max(anszr,zr);
				}
				if(sum+num*l+zr+(numzero-1)*zl>=10000){
					//if(r==49&&zr==49)
					//printf("4 %d %d %d %d %d\n",l,r,zl,zr,sum+num*l+zr+(numzero-1)*zl);
					ansl=min(ansl,l);
					//ansr=max(ansr,r);
					anszl=min(anszl,zl);
					anszr=max(anszr,zr);
				}
			}

			//if(anszl==0)printf("%d %d %d %d\n",l,r,zl,zr);
		}

	if(num&&numzero&&(ansl==2||ansr==-1||anszl==2||anszr==-1)){
		printf("IMPOSSIBLE\n");return 0;
	}
	if(numzero&&(anszl==2||anszr==-1)){
		printf("IMPOSSIBLE\n");return 0;
	}
	if(num&&(ansl==2||ansr==-1)){
		printf("IMPOSSIBLE\n");return 0;
	}
	if(sum+num*ansr+numzero*anszr<10000||sum+num*ansl+numzero*anszl>10000){
		printf("IMPOSSIBLE\n");return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i])printf("%s %.2lf %.2lf\n",s[i],a[i]+ansl*0.01,a[i]+ansr*0.01);
		else printf("%s %.2lf %.2lf\n",s[i],anszl*0.01,anszr*0.01);
	}
}