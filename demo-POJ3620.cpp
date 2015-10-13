#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m,k;
int graph[105][105];
bool visited[105][105];
int cnt ;
const int diri[]={0,-1,0,1};
const int dirj[]={1,0,-1,0};
void DFS(int i,int j)
{
    visited[i][j]=true;
    cnt++;
    for(int k=0;k<4;k++){
        int mx = i+diri[k];
        int my = j+dirj[k];
        if(mx>=1 && mx<=n && my>=1 && my<=m && !visited[mx][my] && graph[mx][my])
            DFS(mx,my);
    }
}

int main()
{
    freopen("in","r",stdin);
    while(~scanf("%d %d %d",&n,&m,&k)){
        memset(graph,0,sizeof(graph));
        memset(visited,0,sizeof(visited));
        for(int i=0;i<k;i++){
            int u,v;
            scanf("%d %d",&u,&v);
            graph[u][v]=1;//1表示可以走
        }
        int ans = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(!visited[i][j]&&graph[i][j]){
                    cnt = 0;
                    DFS(i,j);
                    ans = max(ans,cnt);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}