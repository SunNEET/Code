//題意：格子上有1,0兩種點,每次選一個點翻轉會把該點和上下左右的點都反轉,求以最少翻轉次數完成的翻轉方式
//思路：若用爆搜把每格都翻轉看看,複雜度是O(2^(M*N)),必爆。所以轉換下想法,假設最上面一列的翻轉方式
//已經決定好了,那想要把上面的轉成白色的就只能由下面去改變它,比方說要翻轉黑色的(1,1)就只能靠(2,1)了。
//依照這種思路一列一列做下來,如果最後一列剩下的(M,1)~(M,N)格子沒有全部變成白色，就代表這樣的步驟不存在。
//所以只要枚舉第一列的翻法,然後剩下幾列就一直設法去翻掉上面的黑色就好,複雜度O(M*N*2^N)。

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_M 16
#define MAX_N 16
const int dx[]={-1,0,0,0,1};
const int dy[]={0,-1,0,1,0};
int M,N;
int tile[MAX_M][MAX_N];
int opt[MAX_M][MAX_N];//儲存最佳解
int flip[MAX_M][MAX_N];//作業用

//調查(x,y)的顏色
int get(int x,int y)
{
    int c = tile[x][y];
    for(int d=0;d<5;d++){
        int x2 = x+dx[d],y2=y+dy[d];
        if(0 <= x2 && x2 < M && 0 <= y2 && y2 < N){
            c += flip[x2][y2];
        }
    }
    return c%2;
}
// 求取決定第一列時的最少操作次數
// 解答不存在的話就是 -1
int calc()
{
    //求取第二列以後的反轉方式
    for(int i=1;i<M;i++){
        for(int j=0;j<N;j++){
            if(get(i-1,j)==1){
                //如果(i-1,j)是黑色的話,就只能翻轉格子了
                flip[i][j]=1;
            }
        }
    }
    //檢查最後一列是否全是白色
    for(int j=0;j<N;j++){
        if(get(M-1,j)!=0){
            //沒有答案
            return -1;
        }
    }
    int cnt = 0;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            cnt += flip[i][j];
        }
    }
    return cnt;
}
int solve()
{
    int res = -1;
    //依字典順序嘗試第一列的所有情況
    for(int i=0;i<1<<N;i++){
        memset(flip,0,sizeof(flip));
        for(int j=0;j<N;j++){
            flip[0][N-j-1]=i>>j&1;
        }
        int num = calc();
        // printf("num=%d\n",num);
        if(num >= 0 && (res < 0 || num < res)){
            res = num;
            memcpy(opt,flip,sizeof(flip));
        }
    }
    return res;
}

int main()
{   
    // freopen("in","r",stdin);
    // freopen("out","w",stdout);
    while(~scanf("%d%d",&M,&N)){
        memset(tile,0,sizeof(tile));
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                scanf("%d",&tile[i][j]);
            }
        }
       
        int ans = solve();
        if(ans==-1)
            printf("IMPOSSIBLE\n");
        else{
            for(int i=0;i<M;i++){
                for(int j=0;j<N;j++){
                    if(j)
                        printf(" ");
                    printf("%d",opt[i][j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}