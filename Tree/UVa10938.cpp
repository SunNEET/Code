#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>
#include <climits>
#include <queue>
#include <map>
#include <cmath>
#include <sstream>
#include <bitset>
using namespace std;

vector<int> adj[5005];
bool visited[5005];
int t_dep,t_dep2;
bool finish;
void DFS(int u,int t,int dep,vector<int>& ans)
{
    if(u==t){
        t_dep = dep/2;
        if(dep%2==1) t_dep2=(dep+1)/2;
        finish=true;
    }
    visited[u]=true;
    for(int j=0;j<adj[u].size()&&!finish;j++){
        int v = adj[u][j];
        if(!visited[v])
            DFS(v,t,dep+1,ans);
    }
    if(dep==t_dep||dep==t_dep2)
        ans.push_back(u);
    return;
}

int main()
{   
    // freopen("in","r",stdin);
    int n;
    while(scanf("%d",&n)&&n){
        int a,b;
        for(int i=0;i<n+1;i++) adj[i].clear();
        for(int i=0;i<n-1;i++){
            scanf("%d %d",&a,&b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int l,s,t;
        scanf("%d",&l);
        for(int i=0;i<l;i++){
            scanf("%d %d",&s,&t);
            t_dep = t_dep2 = 9999999; finish=false;
            vector<int> ans;
            memset(visited,0,sizeof(visited));
            DFS(s,t,0,ans);
            if(ans.size()==1)
                printf("The fleas meet at %d.\n",ans[0]);
            if(ans.size()==2)
                printf("The fleas jump forever between %d and %d.\n",min(ans[0],ans[1]),max(ans[0],ans[1]));
        }

    }    
    return 0;
}
