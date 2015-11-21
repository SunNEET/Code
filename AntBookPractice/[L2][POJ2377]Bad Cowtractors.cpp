// 題意：牛被坑了，所以要拉最大花費，連通每個點的線路。

// 做法：最大生成樹。

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
    int u,v,w;
    edge(int _u,int _v,int _w):u(_u),v(_v),w(_w){}
    bool operator<(const edge& b)const{
        return w > b.w;
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
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            ve.push_back(edge(u,v,w));
        }
        sort(ve.begin(),ve.end());
        int mst = 0,e_cnt = 0;
        for(int i=0;i<ve.size();i++){
            edge e = ve[i];
            if(!isSameSet(e.v,e.u)){
                e_cnt++;
                Union(e.v,e.u);
                mst += e.w;
            }
        }
        if(e_cnt != n-1)
            puts("-1");
        else
            printf("%d\n",mst);
    }
    return 0;
}