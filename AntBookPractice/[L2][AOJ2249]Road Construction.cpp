// 題意：ACM之王要在全國改造交通網絡，第一保證首都最短路，第二保證最低花費。

// 做法：乍看之下很像最小生成樹，因為他想從原本的邊中刪去一些邊，只留下可以讓每點連通，且消耗最少的邊
// 但題目還有一個限制，就是原本首都跟城市間的最短距離，不能因為刪邊而變長。換句話說，就是要用原本給的
// 邊找首都到每個點的最短路嘛，阿竟然首都到每個點的最短路都有了，因為路是雙向，就表示每個點都連通了，
// 所以構成最短路的道路就是我們計算要留下來的路。需要注意的是，如果到某個點的最短路距離相同，就要去
// 比較他們的邊的消耗，取比較小的那個。

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
struct edge{
    int v,len,cost;
    edge(int _v,int _len,int _cost):v(_v),len(_len),cost(_cost){}
};
vector<edge> adjList[10005];
priority_queue<pii,vector<pii>,greater<pii> > pq;
int N,M;

int Dijkstra(int s)
{
    int dist[10005];
    int path[10005];//最短路上,path[u]=v := u的前一個點是從v走來的
    int cost[10005];//cost[v] := 最短路上v的前一個點,走向v所花費的消耗
    memset(dist,0x3f3f,sizeof(dist));
    dist[s] = 0;
    pq.push(make_pair(0,s));
    while(!pq.empty()){
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        for(int j=0;j<adjList[u].size();j++){
            edge e = adjList[u][j];
            if(dist[u]+e.len < dist[e.v]){
                dist[e.v] = dist[u]+e.len;
                cost[e.v] = e.cost;
                pq.push(make_pair(dist[e.v],e.v));
            }
            if(dist[u]+e.len == dist[e.v])
                cost[e.v] = min(cost[e.v],e.cost);
        }
    }
    int sum = 0;
    for(int i=2;i<=N;i++){
        sum += cost[i];
    }
    return sum;
}

int main()
{   
    // freopen("in","r",stdin);
    
    while(scanf("%d%d",&N,&M)&&(N+M)){
        for(int i=0;i<=N;i++) adjList[i].clear();
        int u,v,d,c;
        for(int i=0;i<M;i++){
            scanf("%d%d%d%d",&u,&v,&d,&c);
            adjList[u].push_back(edge(v,d,c));
            adjList[v].push_back(edge(u,d,c));
        }
        int ans = Dijkstra(1);
        printf("%d\n",ans);
    }

    return 0;
}