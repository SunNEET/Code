//思路：最大生成樹。將徵招a且使用a和b的關係,想成是以邊連結a與b的有向圖(b->a),用原本需要的花費去扣掉
//最大生成樹省下的錢就是解了
#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <utility>
#include <map>
#include <algorithm>
#include <bitset>
#include <iostream>
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
struct edge{
    int u,v,w;
    edge(int _u,int _v,int _w):u(_u),v(_v),w(_w){}
    bool operator<(const edge& other)const{
        return w < other.w;
    }
};
vector<edge> ve;
int parent[20005];
int find_set(int u)
{
    if(parent[u]==u)
        return u;
    return parent[u]=find_set(parent[u]);
}
void Union(int x,int y){
    int sx = find_set(x);
    int sy = find_set(y);
    if(sx!=sy){
        parent[sy]=sx;
    }
}
bool isSame(int x,int y){
    return find_set(x)==find_set(y);
}

int main()
{   
    // freopen("in","r",stdin);
    int n,m,r;
    int t;
    scanf("%d",&t);
    while(t--){
        ve.clear();
        scanf("%d%d%d",&n,&m,&r);
        int u,v,w;
        for(int i=0;i<r;i++){
            scanf("%d%d%d",&u,&v,&w);
            ve.push_back(edge(u,n+v,-w));//將男女編號統ㄧ才能建圖ㄧ張圖,男生為0~n-1,女生為n~n+m-1
        }
        sort(ve.begin(),ve.end());
        for(int i=0;i<n+m;i++) parent[i]=i;
        int mst = 0;
        for(int i=0;i<r;i++){
            edge e = ve[i];
            if(!isSame(e.v,e.u)){
                Union(e.v,e.u);
                mst += (-e.w);
            }
        }
        printf("%d\n",10000*(n+m)-mst);
    }
    return 0;
}