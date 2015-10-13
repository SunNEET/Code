#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;
#define MAX_M 200005


bool visited[MAX_M];

struct edge
{
    int to,w;
};
bool operator<(const edge& a,const edge& b)
{
    return a.w > b.w;
}
vector<edge> a[MAX_M];
priority_queue<edge> pq;

void process(int v)
{
    visited[v]=true;
    for(int j=0;j<a[v].size();j++){
        edge e = a[v][j];
        if(!visited[e.to])
            pq.push(e);
    }
}

int Prim()
{
    memset(visited,false,sizeof(visited));
    process(0);//用0當起點,把0接著的邊都加進生成樹
    int mst_cost=0;
    while(!pq.empty()){
        edge e = pq.top();
        pq.pop();
        if(!visited[e.to]){
            //printf("e.to=%d e.w = %d\n",e.to,e.w);
            mst_cost += e.w;
            process(e.to);
        }
    }
    return mst_cost;
}



int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n)&&(m+n)){
        
        for(int i=0;i<m;i++) a[i].clear();
        int u,v,w;
        int total=0;
        for(int i=0;i<n;i++){
            scanf("%d %d %d",&u,&v,&w);
            edge e1,e2;
            e1.to = v; e1.w = w;
            e2.to = u; e2.w = w;
            a[u].push_back(e1);
            a[v].push_back(e2);
            total += w;
        }
        printf("%d\n",total-Prim());
    }

    return 0;
}