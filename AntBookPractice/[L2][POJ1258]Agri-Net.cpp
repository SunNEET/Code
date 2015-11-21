// 題意：求出覆蓋所有點，最短的連接方式

// 思路：裸MST，水之。

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

int N;
struct edge{
    int u,v,w;
    edge(int _u,int _v,int _w):u(_u),v(_v),w(_w){}
    bool operator<(const edge& b)const{
        return w < b.w;
    }
};
vector<edge> ve;
int parent[105];
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
    while(~scanf("%d",&N)){
        ve.clear();
        for(int i=0;i<=N;i++) parent[i]=i;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                int w;
                scanf("%d",&w);
                ve.push_back(edge(i,j,w));
            }
        }
        sort(ve.begin(),ve.end());
        int mst = 0;
        for(int i=0;i<ve.size();i++){
            edge e = ve[i];
            if(!isSameSet(e.v,e.u)){
                mst += e.w;
                Union(e.v,e.u);
            }
        }
        printf("%d\n",mst);
    }
    return 0;
}