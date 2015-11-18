// 題意：給出M條雙向正邊，給出W條單向負邊，判斷有沒有負環。

// 思路：因為對BellmanFord找負環的觀念不清楚，卡非常久。因為對原先對他的理解就是單源最短路，
// 如果說找不到負環，那也是在起點s的情況下而已，想要判斷圖上到底有沒有存在負環，我原先的想法是
// 很天真的對每個點都當起點做一次BellmanFord來判斷，果不其然TLE了。後來才理解，有直接看整張
// 圖是否是BellmanFord的方法，就是令 d[i]=0(0 <= i < V)，然後做V次迴圈，如果在第V次還有鬆
// 弛發生，就表示這張圖上有負環。

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <bitset>
#include <map>
#include <climits>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
using namespace std;
#define INF 1e8
struct edge{
    int v,w;
    edge(int _v,int _w):v(_v),w(_w){}
};
vector<edge> adjList[505];
int N,M,W;
bool findNegative()
{
    int dist[505];
    memset(dist,0,sizeof(dist));
    for(int k=0;k<N;k++){
        for(int u=1;u<=N;u++){
            for(int j=0;j<adjList[u].size();j++){
                edge e = adjList[u][j];
                if( dist[u] + e.w < dist[e.v] ){
                    dist[e.v] = dist[u] + e.w ;
                    if( k== N-1 )
                        return true;
                }
            }
        }
    }
    return false;
}

int main()
{   
    // freopen("in","r",stdin);
    int F;
    scanf("%d",&F);
    while(F--){
        scanf("%d%d%d",&N,&M,&W);
        for(int i=0;i<=N;i++) adjList[i].clear();
        for(int i=0;i<M;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            adjList[u].push_back(edge(v,w));
            adjList[v].push_back(edge(u,w));
        }
        for(int i=0;i<W;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            adjList[u].push_back(edge(v,-w));
        }
        if(findNegative())
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}