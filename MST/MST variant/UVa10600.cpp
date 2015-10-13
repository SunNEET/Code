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
struct edge
{
	int u,v,w,idx;
	edge(int _u,int _v,int _w,int _idx){u=_u;v=_v;w=_w;idx=_idx;}
};
bool operator<(const edge& a,const edge& b)
{
	return a.w < b.w;
}
int parent[105];
vector<edge> ve;

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


int main()
{
	// freopen("in","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<=n;i++) parent[i]=i;
		ve.clear();
		for(int i=1;i<=m;i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			ve.push_back(edge(u,v,w,i));
		}
		sort(ve.begin(),ve.end());
		int mst=0;
		vector<int> mst_edge;
		for(int i=0;i<ve.size();i++){
			edge e = ve[i];
			if(!isSameSet(e.u,e.v)){
				Union(e.u,e.v);
				mst_edge.push_back(e.idx);
				mst+=e.w;
			}
		}
		int sec_mst=INT_MAX,res;
		//每次嘗試拿掉一條原本MST上的邊,然後不用這條邊的情況下做新MST
		for(int k=0;k<mst_edge.size();k++){//v-1條邊
			int flag_edge = mst_edge[k];
			for(int i=0;i<=n;i++) 
				parent[i]=i;
			res = 0;
			// printf("Removed -> edge%d\n",mst_edge[k]);
			int cnt=0;
			for(int i=0;i<ve.size();i++){
				edge e = ve[i];
				if(!isSameSet(e.u,e.v) && e.idx!=flag_edge){
					Union(e.u,e.v);
					res+=e.w;
					cnt++;
				}
			}
			// printf("cnt=%d,res=%d\n",cnt,res);
			if(cnt==n-1)
				sec_mst = min(sec_mst,res);
		}
		printf("%d %d\n",mst,sec_mst);
	}
	return 0;
}