// 題意：一隻母牛從N塊田中的任一塊(1≤N≤1000)去參加盛大的母牛聚會，這個聚會被安排在X號田(1≤X ≤N)。
// 一共有M(1 ≤ M ≤ 100,000)條單行道分別連接著兩塊田，且通過路i需要花Ti(1≤Ti≤100)的時間。
// 每頭母牛必需參加宴會並且在宴會結束時回到自己的領地，但是每頭牛都很懶而喜歡選擇化時間最少的一個
// 方案。來時的路和去時的可能不一樣。求最少要多久所有牛才會回到自己的田。

// 思路：以X點為起點做一次Dijkstra求出回程的最短路,再用剩下的當起點做Dijkstra求去程得最短路,兩者相加。

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
typedef pair<int,int> pii;
struct edge{
    int v,w;
    edge(int _v,int _w):v(_v),w(_w){}
};
vector<edge> adjList[1005];
priority_queue<pii,vector<pii>,greater<pii> > pq;

int distX[1005];
void Dijkstra_X(int s)
{
    memset(distX,0x3f3f,sizeof(distX));
    distX[s] = 0;
    pq.push(make_pair(0,s));
    while(!pq.empty()){
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        for(int j=0;j<(int)adjList[u].size();j++){
            edge e = adjList[u][j];
            if(distX[u]+e.w < distX[e.v]){
                distX[e.v] = distX[u]+e.w;
                pq.push(make_pair(distX[e.v],e.v));
            }
        }
    }
}
int Dijkstra_Other(int s,int t)
{
    int dist[1005];
    memset(dist,0x3f3f,sizeof(dist));
    dist[s] = 0;
    pq.push(make_pair(0,s));
    while(!pq.empty()){
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        for(int j=0;j<(int)adjList[u].size();j++){
            edge e = adjList[u][j];
            if(dist[u]+e.w < dist[e.v]){
                dist[e.v] = dist[u] + e.w;
                pq.push(make_pair(dist[e.v],e.v));
            }
        }
    }
    return dist[t] + distX[s];
}

int main()
{   
    // freopen("in","r",stdin);
    int N,M,X;
    scanf("%d%d%d",&N,&M,&X);
    for(int i=0;i<=N;i++) adjList[i].clear();
    for(int i=0;i<M;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        adjList[u].push_back(edge(v,w));
    }
    Dijkstra_X(X);
    
    int ans = 0;
    for(int i=1;i<=N;i++){
        if(i!=X)
            ans = max(ans,Dijkstra_Other(i,X));
    }
    printf("%d\n",ans);
    return 0;
}