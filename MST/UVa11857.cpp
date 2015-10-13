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
#define MAX_N 1000005
struct edge
{
    int to,w;
};
bool operator<(const edge& a,const edge& b)
{
    return a.w > b.w;
}
vector<edge> a[MAX_N];
priority_queue<edge> pq;
bool visited[MAX_N];
int n,m;

void process(int u)
{
    visited[u]=true;
    for(int j=0;j<a[u].size();j++){
        edge e = a[u][j];
        if(!visited[e.to]){
            pq.push(e);
        }
    }
}
int MaxW;
int Prim()
{
    int mst=0;
    memset(visited,false,sizeof(visited));
    process(0);
    while(!pq.empty()){
        edge e = pq.top();
        pq.pop();
        if(!visited[e.to]){
            process(e.to);
            mst += e.w;
            if(e.w>MaxW)
                MaxW = e.w;
        }
    }
    return mst;
}
bool arriveAll()
{
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            return false;
        }
    }
    return true;
}

int main()
{
    //freopen("in","r",stdin);
    while(scanf("%d %d",&n,&m)&&(n+m)){
        for(int i=0;i<n;i++) a[i].clear();

        int u,v,w;
        for(int i=0;i<m;i++){
            edge e;
            scanf("%d %d %d",&u,&v,&w);
            e.to = v; 
            e.w = w;
            a[u].push_back(e);
            e.to = u;
            a[v].push_back(e);
        }
        MaxW=0;
        int mst = Prim();
        if(arriveAll()){
            if(mst)
                printf("%d\n",MaxW);
            else
                printf("IMPOSSIBLE\n");
        }
        else
            printf("IMPOSSIBLE\n");
    }

    
    
    return 0;
}