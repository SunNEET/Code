題意：有水路和旱路兩種路，走水路必須搭船，且船會停在你下船的那個城市，之後要走水路必須回到該城市才能搭
題目會給出要拜訪的城市順序，求出這順序下能走出來的最短路。

思路：兩組多源最短路+DP。分別用FloydWarshall求出只走水路的和只走陸路的，任意兩點的最短路。
然後令dp[i][j] := 往第i個要求的城市走,船停在j城市的情況下,能得到的最短路。因為一開始必定從
第一個要求的城市出發，所以將dp[0][order[0]]初始化為0，然後往下一個指定城市的最短路可能是
1. 只走陸路，所以把考慮前一個城市所有停船位置的最短路，但只加現在要走的陸路長度上去
即為 dp[i+1][j] = min(dp[i+1][j],dp[i][j]+land[order[i]][order[i+1]]);
2. 要走水路，走水路的話就會改變船的停泊位置，所以DP表格填值的部分會變成
dp[i+1][k] = min(dp[i+1][k],dp[i][j]+land[order[i]][j]+sea[j][k]+land[k][order[i+1]]);

#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#include <iostream>
using namespace std;
typedef long long ll;

int N,M,R;
int land[205][205];
int sea[205][205];
int order[1005];

void floydWarshall()
{
    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(i==j)
                    land[i][j] = sea[i][j] = 0;
                if(land[i][k]+land[k][j]<land[i][j]) 
                    land[i][j] = land[i][k]+land[k][j];
                if(sea[i][k]+sea[k][j]<sea[i][j])
                    sea[i][j] = sea[i][k]+sea[k][j];
            }
        }
    }
}

int solve()
{
    int dp[1005][205];
    memset(dp,0x3f3f,sizeof(dp));
    dp[0][order[0]] = 0;
    for(int i=0;i+1<R;i++){
        for(int j=1;j<=N;j++){
            if(dp[i][j]==0x3f3f3f3f)
                continue;
            dp[i+1][j] = min(dp[i+1][j],dp[i][j]+land[order[i]][order[i+1]]);
            for(int k=1;k<=N;k++){
                dp[i+1][k] = min(dp[i+1][k],dp[i][j]+land[order[i]][j]+sea[j][k]+land[k][order[i+1]]);
            }
        }
    }

    int ans = 0x3f3f3f3f;
    for(int j=1;j<=N;j++)
        ans = min(ans,dp[R-1][j]);
    return ans;
}

int main()
{   
    // freopen("in","r",stdin);
    while(scanf("%d%d",&N,&M) && (N+M)){
        memset(land,0x3f3f,sizeof(land));
        memset(sea,0x3f3f,sizeof(sea));
        for(int i=0;i<M;i++){
            int u,v,d;
            char c;
            scanf("%d%d%d %c",&u,&v,&d,&c);
            if(c=='L')
                land[u][v]=land[v][u]=d;
            else
                sea[u][v]=sea[v][u]=d;
        }
        scanf("%d",&R);
        for(int i=0;i<R;i++)
            scanf("%d",&order[i]);
        floydWarshall();
        int ans = solve();
        printf("%d\n",ans);
    }
}