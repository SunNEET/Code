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
#include <utility>
#include <sstream>
using namespace std;
#define MAX_V 10001

vector<int> a[MAX_V];
bool visited[MAX_V];
int curMaxDep = 0;
int longestV;
int DFSspt[MAX_V];
void DFS(int u,int dep)
{
    // printf("curMaxDep = %d dep =%d u=%d\n",curMaxDep,dep,u);
    visited[u]=true;
    if(dep>curMaxDep){
        curMaxDep = dep;
        longestV = u;
    }
    for(int j=0;j<a[u].size();j++){
        int v = a[u][j];
        if(!visited[v]){
            DFS(v,dep+1);
        }
    }
}
int findCentral(int v1,int v2,int dep)
{
    visited[v1]=true;
    DFSspt[dep]=v1;
    int ansDep = -1 ;
    if(v1 == v2){
        // puts("!!!");
        return dep/2;
    }
    for(int j=0;j<a[v1].size();j++){
        int v = a[v1][j];
        if(!visited[v]){
            ansDep = findCentral(v,v2,dep+1);
        }
        if(ansDep != -1)
            break;
    }
    // printf("ansDep = %d\n",ansDep);
    return ansDep;
}

int main()
{
    freopen("in","r",stdin);
    // freopen("out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++) a[i].clear();
        int u,v;
        for(int i=0;i<n-1;i++){
            scanf("%d %d",&u,&v);
            a[u].push_back(v);
            a[v].push_back(u);
        }
        memset(visited,false,sizeof(visited));
        curMaxDep = 0;  DFS(0,0);
        int v1 = longestV;
        // printf("v1 = %d\n",v1);
        memset(visited,false,sizeof(visited));
        curMaxDep = 0;  DFS(v1,0);
        int v2 = longestV;
        // printf("v2 = %d\n",v2);
        memset(visited,false,sizeof(visited));
        memset(DFSspt,0,sizeof(DFSspt));
        printf("%d\n",DFSspt[findCentral(v2,v1,0)]);
        // for(int i=0;i < n-1 ;i++)
        //     printf("%d ",DFSspt[i]);
        // puts("");
    }
    
    return 0;
}