#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>
#include <climits>
#include <queue>
#include <map>
#include <cmath>
#include <sstream>
using namespace std;
struct edge{
	int u,v,w;
	edge(int _u,int _v,int _w){
		u = _u;
		v = _v;
		w = _w;
	}
};
bool operator<(const edge& a,const edge& b){
	return a.w > b.w;
}
struct s_edge{
	int v,w;
	s_edge(int _v,int _w){
		v = _v;
		w = _w;
	}
};
vector<edge> ve;
vector<s_edge> adjList[105];
int parent[105];

int findSet(int u)
{
	if(parent[u]==u)
		return u;
	return parent[u]=findSet(parent[u]);
}
void Union(int x,int y)
{
	int px = findSet(x);
	int py = findSet(y);
	if(px!=py)
		parent[px]=py;
}
bool isSameSet(int x,int y)
{
	return findSet(x)==findSet(y);
}
bool visited[105];
int res;
bool DFS(int u,int t,int Min)
{
	visited[u]=true;
	if(u==t)
		return true;
	for(int j=0;j<adjList[u].size();j++){
		s_edge e = adjList[u][j];
		if(!visited[e.v]){
			int nxt_Min = min(Min,e.w);
			if(DFS(e.v,t,nxt_Min)){
				res = nxt_Min;
			}
		}
	}
	return false;
}

int main()
{
	// freopen("in","r",stdin);
	int N,R,cas=1;
	while(scanf("%d%d",&N,&R)&&(N+R)){
		for(int i=0;i<=N;i++){
			parent[i]=i;
			adjList[i].clear();
		}
		ve.clear();
		for(int i=0;i<R;i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			ve.push_back(edge(u,v,w));
		}
		sort(ve.begin(),ve.end());
		int s,t,p;
		scanf("%d%d%d",&s,&t,&p);
		for(int i=0;i<ve.size();i++){
			edge e = ve[i];
			if(!isSameSet(e.u,e.v)){
				Union(e.u,e.v);
				adjList[e.u].push_back(s_edge(e.v,e.w));
				adjList[e.v].push_back(s_edge(e.u,e.w));
			}
		}
		res = 1;
		memset(visited,0,sizeof(visited));
		DFS(s,t,INT_MAX);
		// printf("res=%d\n",res);
		int ans;
		// printf("res=%d\n",res);
		ans = (p%res==0)? p/(res-1) : p/(res-1)+1;
		printf("Scenario #%d\n",cas++);
		printf("Minimum Number of Trips = %d\n",ans);
		printf("\n");
	}

	return 0;
}