#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <climits>
using namespace std;

struct edge
{
	int u,v,w;
	edge(int _u=0,int _v=0,int _w=0){ u=_u;v=_v;w=_w;}
};
struct s_edge{
	int v,w;
	s_edge(int _v=0,int _w=0){v=_v;w=_w;}
};
bool operator< (const edge& a,const edge& b)
{
	return a.w > b.w;
}
vector<edge> ve;
vector<s_edge> adjList[205];
int parent[205];
int findSet(int u)
{
	if(parent[u]==u)
		return u;
	return parent[u]=findSet(parent[u]);
}
void Union(int x,int y)
{
	int px=findSet(x);
	int py=findSet(y);
	if(px!=py)
		parent[px]=py;
}
bool isSameSet(int x,int y)
{
	return findSet(x)==findSet(y);
}
bool visited[205];
int ans;
bool DFS(int u,int end,int Min)
{	
	visited[u]=true;
	if(u==end)
		return true;
	for(int j=0;j<adjList[u].size();j++){
		s_edge e = adjList[u][j];
		if(!visited[e.v]){
			int nxt_Min = min(Min,e.w);
			if(DFS(e.v,end,nxt_Min)){
				ans = min(ans,nxt_Min);
			}
		}
	}
	return false;
}

int main()
{	
	// freopen("in","r",stdin);
	int n,r;
	int sce=1;
	while(scanf("%d %d ",&n,&r)&&(n+r)){
		string s1,s2;
		map<string,int> msi;
		msi.clear();
		ve.clear();
		for(int i=0;i<=n;i++) adjList[i].clear();
		for(int i=0;i<=n;i++) parent[i]=i;
		memset(visited,0,sizeof(visited));
		int num = 0;
		for(int i=0;i<r;i++){
			int u,v,w;
			cin >> s1 >> s2 ;
			scanf("%d ",&w);
			if(msi.find(s1)==msi.end())
				msi[s1]=num++;
			if(msi.find(s2)==msi.end())
				msi[s2]=num++;
			u = msi[s1]; v = msi[s2];
			ve.push_back(edge(u,v,w));
		}
		int s,t;
		cin >> s1 >> s2;
		s = msi[s1]; t = msi[s2];
		sort(ve.begin(),ve.end());
		for(int i=0;i<ve.size();i++){
			edge e = ve[i];
			if(!isSameSet(e.u,e.v)){
				Union(e.u,e.v);
				adjList[e.u].push_back(s_edge(e.v,e.w));
				adjList[e.v].push_back(s_edge(e.u,e.w));
			}
		}
		for(int i=0;i<n;i++){
			vector<s_edge> ves = adjList[i];
			for(int j=0;j<ves.size();j++){
				s_edge e = adjList[i][j];
				// printf("%d->%d = %d\n",i,e.v,e.w);
			}
		}
		ans = INT_MAX>>1;
		DFS(s,t,INT_MAX);
		printf("Scenario #%d\n",sce++);
		printf("%d tons\n",ans);
		puts("");
	}

	return 0;
}