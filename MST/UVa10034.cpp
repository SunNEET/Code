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
#define MAX_N 105
int n;
struct edge
{
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
bool visited[MAX_N];
void Process(int u)
{
    visited[u] = true;
    for(int j=0;j<a[u].size();j++){
        edge e = a[u][j];
        if(!visited[e.to])
            pq.push(e);
    }
}

double Prim()
{
    memset(visited,false,sizeof(visited));
    Process(0);
    double mst_cost = 0;
    while(!pq.empty()){
        edge e = pq.top();
        pq.pop();
        if(!visited[e.to]){
            mst_cost += e.w;
            Process(e.to);
        }
    }
    return mst_cost;
}


int main()
{
    //freopen("in","r",stdin);
    int t,cnt=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        vP.clear();
        for(int i=0;i<n;i++) a[i].clear();
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
                    a[p1.index].push_back(e);
                    e.to = p1.index;
                    a[p2.index].push_back(e);
                }
            }
        }
        if(cnt++)
            puts("");
        printf("%.2lf\n",Prim());
    }
    return 0;
}