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
#define MAX_N 2005
typedef long long ll;
struct edge
{
    int to,w;
};
bool operator< (const edge& a,const edge& b)
{
    return a.w > b.w;
}
vector<edge> a[MAX_N];
priority_queue<edge> pq;
map<string,int> strNo;
bool visited[MAX_N];

void process(int u)
{
    visited[u]=true;
    for(int j=0;j<a[u].size();j++){
        edge e = a[u][j];
        if(!visited[e.to])
            pq.push(e);
    }
}

ll Prim(int u)
{
    process(u);
    ll mst_cost = 0;
    while(!pq.empty()){
        edge e = pq.top();
        pq.pop();
        if(!visited[e.to]){
            mst_cost += e.w;
            process(e.to);
        }
    }
    return mst_cost;
}


int main()
{
    //freopen("in","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,u,v,w,sNo=0;
        string sa,sb;
        
        strNo.clear();
        scanf("%d %d ",&n,&m);
        for(int i=0;i<MAX_N;i++) 
            a[i].clear();
        for(int i=0;i<m;i++){
            cin >> sa >> sb >> w;
            //printf("strNo.size() = %lu ",strNo.size());
            if(strNo.find(sa)==strNo.end())
                strNo[sa] = sNo++;
            if(strNo.find(sb)==strNo.end())
                strNo[sb] = sNo++;
            //printf("strNo.size() = %lu sa = %d,sb = %d\n",strNo.size(),strNo[sa],strNo[sb]);
            u = strNo[sa];  v = strNo[sb];
            edge e1,e2;
            e1.to = v; e1.w = w;
            a[u].push_back(e1);
            e2.to = u; e2.w = w;
            a[v].push_back(e2);
        }
        ll ans=0;
        memset(visited,false,sizeof(visited));
        for(int i=0;i<n;i++){
            if(!visited[n])
                ans += Prim(i);
        }
        printf("%lld\n",ans);
        if(t)
            printf("\n");
    }
    return 0;
}