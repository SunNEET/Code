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
	int u,v;
	double w;
	edge(int _u,int _v,double _w){
		u = _u;
		v = _v;
		w = _w;
	}
};
bool operator<(const edge& a,const edge& b){
	return a.w < b.w;
}
struct point{
	int x,y,idx;
	point(int _x,int _y,int _idx){
		x=_x; y=_y; idx=_idx;
	}
};
vector<edge> ve;
vector<point> vp;

int parent[1005];
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
		int n;
		scanf("%d",&n);
		for(int i=0;i<=n;i++)
			parent[i]=i;
		ve.clear();
		vp.clear();
		for(int i=1;i<=n;i++){
			int x,y;
			scanf("%d %d",&x,&y);
			vp.push_back(point(x,y,i));
		}
		for(int i=0;i<n-1;i++){
			point p1 = vp[i];
			for(int j=i+1;j<n;j++){
				point p2 = vp[j];
				ve.push_back(edge(p1.idx,p2.idx,hypot(p1.x-p2.x,p1.y-p2.y)));
			}
		}
		sort(ve.begin(),ve.end());
		int m;
		scanf("%d",&m);
		int cnt=0;
		for(int i=0;i<m;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			u--;v--;
			point p1 = vp[u];
			point p2 = vp[v];
			if(!isSameSet(p1.idx,p2.idx)){
				Union(p1.idx,p2.idx);
				cnt++;
			}
		}
		if(cnt==n-1)
			puts("No new highways need");
		else{
			for(int i=0;i<ve.size() && cnt < n-1;i++){
				edge e = ve[i];
				if(!isSameSet(e.u,e.v)){
					Union(e.u,e.v);
					printf("%d %d\n",e.u,e.v);
					cnt++;
				}
			}
		}
		if(t)
			printf("\n");
	}
	return 0;
}