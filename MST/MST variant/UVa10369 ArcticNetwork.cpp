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

struct point
{
	int idx;
	double x,y;
	point(int _idx,double _x=0.0,double _y=0.0){idx=_idx;x=_x;y=_y;};
};
struct edge
{
	int u,v;
	double w;
	edge(int _u,int _v,double _w){
		u=_u; v=_v; w=_w;
	}
};
bool operator<(const edge& a,const edge& b)
{
	return a.w < b.w;
}
vector<point> vp;
vector<edge> ve;

int parent[505];
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
		vp.clear();
		ve.clear();
		int s,p;
		scanf("%d%d",&s,&p);
		for(int i=0;i<=p;i++) parent[i]=i;
		for(int i=0;i<p;i++){
			int x,y;
			scanf("%d %d",&x,&y);
			vp.push_back(point(i,x,y));
		}
		for(int i=0;i<p-1;i++){
			point p1 = vp[i];
			for(int j=i+1;j<p;j++){
				point p2 = vp[j];
				double w = hypot(abs(p1.x-p2.x),abs(p1.y-p2.y));
				// printf("%.2lf\n",w);
				ve.push_back(edge(p1.idx,p2.idx,w));
			}
		}
		sort(ve.begin(),ve.end());
		vector<double> ans;
		for(int i=0;i<ve.size();i++){
			edge e = ve[i];
			if(!isSameSet(e.u,e.v)){
				Union(e.u,e.v);
				ans.push_back(e.w);
			}
		}
		//MST總共有p-1條邊,因為後面s-1條直接分給衛星連結,取沒被分掉的最後一條 
		printf("%.2lf\n",ans[(p-1)-(s-1)-1]);
	}
	return 0;
}