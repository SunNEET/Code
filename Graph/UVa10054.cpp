#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <climits>
#include <queue>
#include <map>
#include <cmath>
#include <sstream>
#include <bitset>
using namespace std;
#define MAX_V 50
int m[MAX_V+1][MAX_V+1];
int degree[MAX_V+1];
bool vis[MAX_V+1][MAX_V+1];
bool existEC(int n)
{
    for(int u=1;u<=MAX_V;u++){
        for(int v=1;v<=MAX_V;v++){
            degree[u]+=m[u][v];//從u連出的edge數
        }
    }
    for(int i=1;i<=MAX_V;i++){
        if(degree[i]%2==1)
            return false;
    }
    return true;
}
void init()
{
    memset(m,0,sizeof(m));
    memset(degree,0,sizeof(degree));
    memset(vis,0,sizeof(vis));
}
void Euler(int u)
{
    for(int v=1;v<=MAX_V;v++){
        if(m[u][v]){
            m[u][v]--; m[v][u]--;
            Euler(v);
            printf("%d %d\n",v,u);
        }
    }
    return ;
}

int main()
{   
    // freopen("in","r",stdin);
    int t,test=0,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        init();
        int u,v,st;
        for(int i=0;i<n;i++){
            scanf("%d %d",&u,&v);
            m[u][v]++;
            m[v][u]++;
        }
        printf("Case #%d\n", ++test);
        if(!existEC(n))
            puts("some beads may be lost");
        
        else{
            for(int i=1;i<MAX_V;i++)
                if(degree[i])
                    st=i;
            Euler(st);
        }
        if(t)
            puts("");
    }
    return 0;
}
