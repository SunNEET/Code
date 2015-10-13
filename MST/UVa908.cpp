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
int n,k,m;

void Process(int u)
{
    visited[u]=true;
    for(int j=0;j<a[u].size();j++){
        edge e = a[u][j];
        if(!visited[e.to])
            pq.push(e);
    }

}


int Prim()
{
    memset(visited,false,sizeof(visited));
    Process(1);
    int min_cost=0;
    while(!pq.empty())
    {
        edge e = pq.top();
        pq.pop();
        if(!visited[e.to]){
            Process(e.to);
            min_cost+=e.w;
        }
    }
    return min_cost;
}




int main()
{
    //freopen("in","r",stdin);
    int cnt=0;
    while(~scanf("%d",&n)){
        for(int i=0;i<MAX_N;i++) a[i].clear();
        int u,v,w,preCost=0;
        for(int i=0;i<n-1;i++){
            scanf("%d %d %d",&u,&v,&w);
            preCost+=w;
        }
        scanf("%d",&k);
        for(int i=0;i<k;i++){
            edge e1,e2;
            scanf("%d %d %d",&u,&v,&w);
            e1.to = v; e1.w = w;
            e2.to = u; e2.w = w;
            a[u].push_back(e1);
            a[v].push_back(e2);
        }
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            edge e1,e2;
            scanf("%d %d %d",&u,&v,&w);
            e1.to = v; e1.w = w;
            e2.to = u; e2.w = w;
            a[u].push_back(e1);
            a[v].push_back(e2);
        }
        if(cnt)
            puts("");
        printf("%d\n%d\n",preCost,Prim());
        cnt++;
    }
   
    return 0;
}