// 題意：給定牛的關係圖，求其中一頭牛與其他牛關係路程之和sum最小，然後輸出sum*100/(n-1)
// 思路：裸FloydWarshall,不過因為我寫的時候腦袋矇矇的,用adjList建圖,索性就用BFS把每個點
// 的最短路跑過一次了。需要注意的是這題有精度問題，四捨五入會錯，所以要用(int)(avg*100)才行。


#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <bitset>
#include <map>
#include <climits>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
using namespace std;
#define INF 1e8

vector<int> adj[305];
int dp[305][305];
bool visited[305];
void BFS(int s)
{
    queue<int> q;
    q.push(s);
    dp[s][s]=0;
    visited[s] = true;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int j=0;j<adj[u].size();j++){
            int v = adj[u][j];
            if(!visited[v]){
                q.push(v);
                visited[v] = true;
                dp[s][v] = dp[s][u] + 1;
            }
        }
    }
}


int main()
{   
    // freopen("in","r",stdin);
    int N,M;
    while(~scanf("%d%d",&N,&M)){
        for(int i=0;i<M;i++){
            int V;
            scanf("%d",&V);
            vector<int> node;
            for(int k=0;k<V;k++){
                int u;
                scanf("%d",&u);
                node.push_back(u);
            }
            for(int x=0;x<(int)node.size();x++){
                int u = node[x];
                for(int y=0;y<(int)node.size();y++){
                    int v = node[y];
                    if(x!=y){
                       adj[u].push_back(v); 
                    }
                }
            }
        }
        for(int i=1;i<=N;i++){
            memset(visited,0,sizeof(visited));
            BFS(i);
        }
        double ans = INF;
        for(int i=1;i<=N;i++){
            double sum = 0;
            for(int j=1;j<=N;j++){
                sum += dp[i][j];
            }
            ans = min(ans,sum);
        }
        double avg = ans/(N-1);
        printf("%d\n",(int)(avg*100));
    }
    return 0;
}