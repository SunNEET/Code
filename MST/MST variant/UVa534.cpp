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
#include <stack>
#include <bitset>
using namespace std;
#define MAX_N 205
int n;
struct edge
{
    int from;
    int to;
    double w;
};
bool operator< (const edge& a,const edge& b)
{
    return a.w > b.w;
}
struct Point
{
    double x,y;
    int index;
};
vector<Point> vP;
vector<edge> a[MAX_N];
priority_queue<edge> pq;
int parent[MAX_N];
bool visited[MAX_N];
double adj[MAX_N][MAX_N];
void Process(int u)
{
    visited[u] = true;
    for(int j=0;j<a[u].size();j++){
        edge e = a[u][j];
        if(!visited[e.to]){
            e.from = u ;
            pq.push(e);
            //parent[e.to] = u;
        }
    }
}

double PrimFIX()
{
    memset(parent,-1,sizeof(parent));
    memset(visited,false,sizeof(visited));
    Process(0);
    double mst_cost = 0;
    while(!pq.empty()){
        edge e = pq.top();
        pq.pop();
        if(!visited[e.to]){
            mst_cost += e.w;
            parent[e.to] = e.from;
            Process(e.to);
        }
    }
    return mst_cost;
}
int main()
{
    //freopen("in","r",stdin);
    //scanf("%d",&t);
    int cnt = 1;
    while(scanf("%d",&n)&&n){
        vP.clear();
        for(int i=0;i<n;i++) a[i].clear();
        memset(adj,0,sizeof(adj));

        double x,y;
        for(int i=0;i<n;i++){
            Point p;
            scanf("%lf %lf",&x,&y);
            p.x = x; p.y = y;
            p.index = i;
            vP.push_back(p);
        }
        for(int i=0;i<n;i++){
            Point p1 = vP[i];
            for(int j=0;j<n;j++){
                if(i!=j){
                    Point p2 = vP[j];
                    edge e;
                    e.to = p2.index; 
                    e.w = sqrt((p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y));
                    //printf("e.w = %lf\n",e.w);
                    a[p1.index].push_back(e);
                    e.to = p1.index;
                    a[p2.index].push_back(e);
                    adj[p1.index][p2.index] = e.w;
                    adj[p2.index][p1.index] = e.w;
                }
            }
        }
        
        PrimFIX();
        // for(int i=0;i<n;i++){
        //     printf("%d ",parent[i]);
        // }
        // printf("\n");
        int cur = 1;
        double ans = 0.000;
        while(parent[cur] != -1 ){
            ans = max(ans,adj[cur][parent[cur]]);
            cur = parent[cur];
        }
        printf("Scenario #%d\n",cnt++);
        printf("Frog Distance = %.3lf\n",ans);
        puts("");
    }
    return 0;
}