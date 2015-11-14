// 題意：2棵蘋果樹在T分鐘內隨機由某一棵蘋果樹掉下一個蘋果，
// 牛站在一號樹下等著吃蘋果，它最多願意移動W次，問它最多能吃到幾個蘋果。

// 思路：用二維表格DP[i][j]表示在前i秒,換j次方向時能拿到的最大頻果數量。
// 因為在第I秒,換過J次方向的情況下,這個情況的最大值取決於之前就在同一棵樹,
// 也就是同樣換J次方向,但在第I-1秒時候的最大值DP[i-1][j]加上現在所在的樹
// 是不是會掉蘋果的;或者是先前在另一棵樹,這次才換到這棵樹來,所以是換過
// J-1次方向,在第I-1秒時候的最大值DP[i-1][j-1]加上現在所在的樹是不是會
// 掉蘋果的，兩者取一，就是現在情況所能獲得的最大值，寫作
// DP[i][j] = max(DP[i-1][j],DP[i-1][j-1])

// 註：現在在哪顆樹只要看j就知道了,因為一開始一定在樹1,如果j是偶數次就表示回到樹1,
// 相對的,j是奇數次,就表示在樹2。

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
    int T,W;
    int a[1005];
    int DP[1005][35];//DP[i][j] := 前i秒,換j次方向時能拿到的頻果數量
    scanf("%d%d",&T,&W);
    for(int i=1;i<=T;i++)
        scanf("%d",&a[i]);
    //初始化,0秒的時候沒有頻果
    for(int j=0;j<=W;j++)
        DP[0][j] = 0;
    //不動的情況拿到的頻果
    for(int i=1;i<=T;i++){
        DP[i][0] = DP[i-1][0];
        if(a[i]==1)
            DP[i][0]++;
    }
    for(int i=1;i<=T;i++){
        for(int j=1;j<=W;j++){
            int cur = 1;
            if(j%2==1)
                cur = 2; 
            DP[i][j] = max(DP[i-1][j-1],DP[i-1][j]);
            DP[i][j] += a[i]==cur? 1 : 0 ;
        }
    }

    int ans = 0;
    for(int j=0;j<=W;j++)
        ans = max(ans,DP[T][j]);
    printf("%d\n",ans);
    return 0;
}