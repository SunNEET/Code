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
#define MAX_N 405
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
int Prim(int u)
{
    int mst=0;
    memset(visited,false,sizeof(visited));
    process(u);
    while(!pq.empty()){
        edge e = pq.top();
        pq.pop();
        if(!visited[e.to]){
            process(e.to);
            mst += e.w;
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
        map<string,int> cityNo;
        string sa,sb;
        for(int i=0;i<n;i++){
            cin >> sa;
            cityNo[sa]=i;
        }
        int u,v,w;
        for(int i=0;i<m;i++){
            cin >> sa >> sb >> w;
            u = cityNo[sa];
            v = cityNo[sb];
            edge e;
            e.to = v;   e.w = w;
            a[u].push_back(e);
            e.to = u;
            a[v].push_back(e);
        }
        int start ;
        cin >> sa;
        start = cityNo[sa];
        int mst = Prim(start);
        if(arriveAll()){
            printf("%d\n",mst);
        }
        else{
            puts("Impossible");
        }
    }
    return 0;
}