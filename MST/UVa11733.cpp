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
struct edge
{
    int to,w;
};
bool operator<(const edge& a,const edge& b)
{
    return a.w > b.w;
}
vector<edge> a[10005];
priority_queue<edge> pq;
bool visited[10005];

void process(int u)
{
    visited[u]=true;
    for(int j=0;j<a[u].size();j++){
        edge e = a[u][j];
        if(!visited[e.to])
            pq.push(e);
    }
}
int A,connectA;
int Prim(int u)
{
    int mst=0;
    process(u);
    while(!pq.empty()){
        edge e = pq.top();
        pq.pop();
        if(!visited[e.to]){
            process(e.to);
            if(e.w >= A){
                connectA++;
                mst += A;
            }
            else  
                mst += e.w;
        }
    }
    return mst;
}

int main()
{
    //freopen("in","r",stdin);
    int t,cnt=1;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d %d",&n,&m,&A);
        for(int i=1;i<=n;i++) a[i].clear();

        int u,v,w;
        for(int i=0;i<m;i++){
            scanf("%d %d %d",&u,&v,&w);
            edge e;
            e.to = v; e.w = w;
            a[u].push_back(e);
            e.to = u;
            a[v].push_back(e);
        }
        int mst=0;
        int startA=0;
        connectA = 0;
        memset(visited,false,sizeof(visited));
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                startA++;
                mst += Prim(i);
            }
        }
        mst += startA*A;
        printf("Case #%d: %d %d\n",cnt++,mst,startA+connectA);
    }
    return 0;
}