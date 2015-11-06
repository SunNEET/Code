//題意：給出ㄧ堆牛的關係,有兩頭牛不能離太遠也有不能離太近的,求最後一頭牛跟第一頭牛的最遠距離
//思路：差分約束的樣子,還不是很會。

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
    int v,w;
    edge(int _v,int _w):v(_v),w(_w){}
};
vector<edge> adj[1005];
int dist[1005];
bool hasNegative(int N)
{
    for(int u=1;u<=N;u++){
        for(int j=0;j<adj[u].size();j++){
            edge e = adj[u][j];
            if(dist[u]+e.w < dist[e.v])
                return true;
        }
    }
    return false;
}
int main()
{   
    // freopen("in","r",stdin);
    int N,ML,MD;
    while(~scanf("%d%d%d",&N,&ML,&MD)){
        for(int i=1;i<=N;i++) adj[i].clear();
        int u,v,w;
        for(int i=0;i+1<=N;i++){
            adj[i+1].push_back(edge(i,0));
        }
        for(int i=0;i<ML;i++){
            scanf("%d%d%d",&u,&v,&w);
            adj[u].push_back(edge(v,w));
        }
        for(int i=0;i<MD;i++){
            scanf("%d%d%d",&u,&v,&w);
            adj[v].push_back(edge(u,-w));
        }
        for(int i=0;i<=N;i++) 
            dist[i] =INT_MAX>>2;

        dist[1]=0;
        for(int i=0;i<=N-1;i++){
            for(int u=0;u<=N;u++){
                for(int j=0;j<adj[u].size();j++){
                    edge e = adj[u][j];
                    if(dist[u]+e.w < dist[e.v])
                        dist[e.v] = dist[u] + e.w;
                }
            }
        }
        if(hasNegative(N))
            puts("-1");
        else if(dist[N] == INT_MAX>>2)
            puts("-2");
        else
            printf("%d\n",dist[N]-dist[1]);
    }
    return 0;
}