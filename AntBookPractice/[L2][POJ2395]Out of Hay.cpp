// 題意：求最大瓶頸路

// 思路：題目沒要特定起點終點上的瓶頸路，所以最後一條加進Kruskal的邊就是答案。

#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#include <iostream>
using namespace std;
typedef long long ll;
int n,m;
struct edge{
    int u,v;
    ll w;
    edge(int _u,int _v,ll _w):u(_u),v(_v),w(_w){}
    bool operator<(const edge& b)const{
        return w < b.w;
    }
};
vector<edge> ve;
int parent[1005];
int findSet(int u)
{
    if(parent[u]==u)
        return u;
    return parent[u] = findSet(parent[u]);
}
void Union(int x,int y)
{
    int px = findSet(x);
    int py = findSet(y);
    if(px!=py)
        parent[px]=py;
}
bool isSameSet(int x,int y){
    return findSet(x) == findSet(y);
}
int main()
{   
    // freopen("in","r",stdin);
    while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<=n;i++) parent[i]=i;
        ve.clear();
        for(int i=0;i<m;i++){
            int u,v;
            ll w;
            scanf("%d%d%lld",&u,&v,&w);
            ve.push_back(edge(u,v,w));
        }
        sort(ve.begin(),ve.end());
        // int path[1005];
        // memset(path,-1,sizeof(path));
        ll longest = 0;
        for(int i=0;i<(int)ve.size();i++){
            edge e = ve[i];
            if(!isSameSet(e.u,e.v)){
                // path[e.v] = e.u;
                longest = max(longest,e.w);
                Union(e.u,e.v);
            }
        }
        printf("%lld\n",longest);
    }
    return 0;
}