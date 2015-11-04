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
#define INF INT_MAX>>2
struct edge
{
    int v,w;
    edge(int _v,int _w):v(_v),w(_w){}
};
vector<edge> adj[5005];
int dist[5005];
int dist2[5005];
priority_queue<ii,vector<ii>,greater<ii> > pq;
void dijkstra(int s)
{
    for(int i=0;i<5005;i++){
        dist[i] = INF;
        dist2[i] = INF;
    }
    dist[s]=0;
    pq.push(make_pair(0,s));
    while(!pq.empty()){
        ii loc = pq.top(); pq.pop();
        int d = loc.first;
        int u = loc.second;
        for(int j=0;j<adj[u].size();j++){
            edge e = adj[u][j];
            if(dist[u]+e.w < dist[e.v]){
                dist[e.v] = dist[u]+e.w;
                pq.push(make_pair(dist[e.v],e.v));
            }
            if(dist[u]+e.w < dist2[e.v] && dist[u]+e.w > dist[e.v]){
                dist2[e.v] = dist[u]+e.w;
                pq.push(make_pair(dist2[e.v],e.v));
            }
            if(dist2[u]+e.w < dist2[e.v]){
                dist2[e.v] = dist2[u]+e.w;
                pq.push(make_pair(dist2[e.v],e.v));
            }
        }   
    }
}

int main()
{   
    // freopen("in","r",stdin);
    int n,r;
    while(~scanf("%d%d",&n,&r)){
        for(int i=0;i<n;i++) adj[i].clear();
        int u,v,w;
        for(int i=0;i<r;i++){
            scanf("%d%d%d",&u,&v,&w);
            adj[u-1].push_back(edge(v-1,w));
            adj[v-1].push_back(edge(u-1,w));
        }
        dijkstra(0);
        printf("%d\n",dist2[n-1]);
    }
    return 0;
}