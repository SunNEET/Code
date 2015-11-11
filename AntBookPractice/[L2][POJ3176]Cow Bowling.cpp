//題意：給出一個三角形,求出從頂點走訪到底的最大總和
//思路：簡單DP。將DP[i]設成從i點向下走所能得到的最大值就好。

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <bitset>
#include <iostream>
using namespace std;

int main()
{   
    // freopen("in","r",stdin);
    int N;
    scanf("%d",&N);
    int DP[61426];//DP[i]:=從第i個節點向下走所能夠得到的最大值
    int val[61426];
    memset(val,0,sizeof(val));
    memset(DP,0,sizeof(DP));
    for(int i=1;i<=(N*(N+1))/2;i++)
        scanf("%d",&val[i]);
    for(int j=1;j<=N;j++)
        DP[(N-1)*N/2+j] = val[(N-1)*N/2+j];
    for(int i=N-1;i>=1;i--){
        int num_st = (i-1)*i/2 ;
        for(int j=1;j<=i;j++){
            int cur_num = num_st+j;
            DP[cur_num] = max(DP[cur_num+i],DP[cur_num+i+1])+val[cur_num];
        }
    }
    printf("%d\n",DP[1]);
    return 0;
}