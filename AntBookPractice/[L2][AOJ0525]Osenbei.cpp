// 題意：有一個烤餅器可以烤r行c列的煎餅，煎餅可以正面朝上（用1表示）也可以背面朝上（用0表示）。
// 一次可將同一行或同一列的煎餅全部翻轉。現在需要把盡可能多的煎餅翻成正面朝上，問最多能使多少煎餅正面朝上？
// 思路：一看就是枚舉，但怎麼舉？思路有點類似POJ 3279,詳細可以參考另一篇。簡單的說,就是只要枚舉列
// 翻跟不翻的所有可能就好,因為這時行的翻轉,只需要考慮每一行上是0多還是1多,將多的那個累加起來,就是
// 目前這種列的翻轉組合所能做出的最佳解。實作上用bitset的flip模擬翻轉,超級好寫。

#include <cstdio>
#include <vector>
#include <algorithm>
#include <bitset>
#include <iostream>
using namespace std;

bitset<10005> board[10];
int ans;
void DFS(int cur_r,const int r,const int c)
{
    if(cur_r==r){
        int res = 0;
        for(int cc = 0;cc < c;cc++){
            int c_num ,c_cnt=0;
            for(int rr = 0;rr < r;rr++){
                if(board[rr][cc]==1)
                    c_cnt++;
            }
            if(c_cnt > r/2)
                c_num = c_cnt;
            else
                c_num = r - c_cnt;
            res += c_num;
        }
        ans = max(ans,res);
        return ;
    }

    DFS(cur_r+1,r,c);
    board[cur_r].flip();
    DFS(cur_r+1,r,c);
    return ;
}

int main()
{   
    // freopen("in","r",stdin);
    int r,c;
    while(scanf("%d%d",&r,&c)&&(r+c)){
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int n;
                scanf("%d\n",&n);
                board[i][j] = n;
            }
        }
        ans = 0;
        DFS(0,r,c);
        printf("%d\n",ans);
    }
    return 0;
}