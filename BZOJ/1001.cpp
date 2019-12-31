#include<bits/stdc++.h>
using namespace std;
struct Edge{
	int u,v,w;
	Edge(){};
	Edge(int _u,int _v,int _w):u(_u),v(_v),w(_w){}
};
const int N=1010;
int head[N],cnt=0;
Edge e[N*N*6];
void init(){
	memset(head,-1,sizeof head);
	cnt=0;
}
void addedge(int u,int v,int w){
	e[cnt]=Edge(head[u],v,w);
	head[u]=cnt++;
	e[cnt]=Edge(head[v],u,0);
	head[v]=cnt++;
}
int dis[N],discnt[N],cur[N];
void bfs(int s,int t){
	memset(dis,-1,sizeof dis);
	memset(discnt,0,sizeof discnt);
	dis[t]=0;
	queue<int>q;q.push(t);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=head[x];i!=-1;i=e[i].u){
			int v=e[i].v;
			if(dis[v]!=-1)continue;
			dis[v]=dis[x]+1;q.push(v);
			++discnt[dis[v]];
		}
	}
}
int dfs(int u,int limit,int s,int t){
	if(u==t)return limit;
	int flow=0;
	for(int& i=cur[u];i!=-1;i=e[i].u){
		int v=e[i].v;
		if(e[i].w>0 && dis[v]==dis[u]-1){
			int res=dfs()
		}
	}
}
int main(){

}