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
typedef long long int ll;

struct edge
{
    int u,v;
    double w;

};
struct City
{
    int x,y,man,index;
};
bool operator<(const edge& a,const edge& b)
{
    return a.w < b.w;
}

vector<edge> ve;
vector<City> vC;
int parent[1005];
int n;

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
        parent[py]=px;
}

bool isSameSet(int x,int y)
{
    if(findSet(x)==findSet(y))
        return true;
    else
        return false;
}
struct simpEdge
{
    int v;
    double w;
    simpEdge(int _v,double _w)
    {
        v=_v;
        w=_w;
    }
};
vector<simpEdge> adjMST[1005];
bool visited[1005];

double dist[1005][1005];//i到j路徑上的最大權重
void DFS(int u,int v,double maxw)
{
    visited[v]=true;
    dist[u][v] = maxw;
    for(int j=0;j<adjMST[v].size();j++){
        simpEdge e = adjMST[v][j];
        if(!visited[e.v]){
            // printf("e.w=%d maxw=%d\n",e.w,maxw);
            maxw = max(maxw,e.w);
            DFS(u,e.v,maxw);
        }
    }
}


int main()
{   
    // freopen("in","r",stdin);
    // freopen("out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        
        scanf("%d",&n);
        ve.clear();
        vC.clear();
        for(int i=0;i<n;i++)
            adjMST[i].clear();
        for(int i=0;i<n;i++){
            City c;
            int x,y,p;
            scanf("%d %d %d",&x,&y,&p);
            c.x = x; c.y = y; c.man=p; c.index = i;
            vC.push_back(c);
        }
        for(int i=0;i<n-1;i++){
            City c1 = vC[i];
            for(int j=i+1;j<n;j++){
                City c2 = vC[j];
                edge e;
                e.u = c1.index;
                e.v = c2.index;
                e.w = sqrt((c2.x-c1.x)*(c2.x-c1.x)+(c2.y-c1.y)*(c2.y-c1.y));
                ve.push_back(e);
            }
        }
        for(int i=0;i<n;i++) 
            parent[i]=i;
        double mst=0,ans=0;
        sort(ve.begin(),ve.end());
        
        set<pair<int,int> > recordEdge;
        recordEdge.clear();
        for(int i=0;i<ve.size();i++){
            edge e = ve[i];
            if(!isSameSet(e.u,e.v)){
                Union(e.u,e.v);
                adjMST[e.u].push_back(simpEdge(e.v,e.w));
                adjMST[e.v].push_back(simpEdge(e.u,e.w));
                mst += e.w;
                recordEdge.insert(make_pair(e.u,e.v));
            }
        }
        memset(visited,0,sizeof(visited));
        memset(dist,0,sizeof(dist));
        for(int i=0;i<n;i++){
            DFS(i,i,0);
            memset(visited,0,sizeof(visited));
        }
        for(int i=0;i<ve.size();i++){
            edge e = ve[i];
            if(recordEdge.find(make_pair(e.u,e.v))!=recordEdge.end()){//此邊在MST裡
                ans = max(ans,(double)( vC[e.u].man + vC[e.v].man)/(mst-e.w) );
            }
            else{//不在MST裡,將此邊先加進MST,形成環,透過移掉原本u->v上的最長邊變次小生成樹
                ans = max(ans,(double)(vC[e.u].man+vC[e.v].man)/(mst-dist[e.u][e.v]));
            }
        }
        printf("%.2f\n",ans);
    }
    return 0;
}
