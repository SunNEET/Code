// 題意：有個嫉妒貓的BBA放了魔法把他們封在環裡，只要不是環，貓就能出來，求拔掉最少總長度的邊就能把所有的環弄掉。


// 做法：最大生成樹。原本給的邊會形成環圍住貓，先記錄原本的總權重，再去找這個圖形的最大生成樹的權重，兩者相減就
// 等於我們從圖形上拔掉的邊的最小總權重。


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
typedef pair<int,int> pii;
int n,m;
struct edge{
    int u,v;
    double w;
    edge(int _u,int _v,double _w):u(_u),v(_v),w(_w){}
    bool operator<(const edge& b)const{
        return w > b.w;
    }
};
vector<edge> ve;
int parent[10005];
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
vector<pii> vp;

int main()
{   
    // freopen("in","r",stdin);
    while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<=n;i++) parent[i]=i;
        ve.clear();
        vp.clear();
        for(int i=0;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            vp.push_back(make_pair(x,y));
        }
        double ori=0;
        for(int i=0;i<m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            u--,v--;
            pii p1 = vp[u];
            pii p2 = vp[v];
            double w = sqrt((p1.first-p2.first)*(p1.first-p2.first)+(p1.second-p2.second)*(p1.second-p2.second));
            ori += w;
            ve.push_back(edge(u,v,w));
        }
        sort(ve.begin(),ve.end());
        double MaxST = 0;
        for(int i=0;i<ve.size();i++){
            edge e = ve[i];
            if(!isSameSet(e.u,e.v)){
                Union(e.u,e.v);
                MaxST += e.w;
            }
        }
        printf("%.3lf\n",ori-MaxST);
    }
    return 0;
}