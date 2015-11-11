// 題意：給出一個N,問有幾種加出這N的方法,數字只能挑2^n次方的數字(ex: 7 = 1+1+1+1+1+1+1 or 1+1+1+1+1+2)
// 思路：需要一點觀察，但一說出來就會秒懂。重點在 奇數偶數 要分開處理，設DP[i]:=i有幾種表示法
// 奇數就是前一個偶數，每種方法都加上一個 1，所以dp[i] = dp[i-1];偶數的話分兩個部分：那些含有1
// 的表示法 跟 其它沒有的，例如 4 就是
// 4 = 1 + 1 + 1 + 1
//   = 1 + 1 + 2
// 和
// 4 = 2 + 2
//   = 4
// 前一個部分就是 3 的每種方法再加 1；後一個部分是 2 的每種方法都乘 2，所以式子寫成：
// dp[i] = dp[i-1] + dp[i/2]
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <bitset>
#include <iostream>
using namespace std;
int DP[1000001];
#define MOD 1000000000
int main()
{   
    // freopen("in","r",stdin);
    int N;
    scanf("%d",&N);
    DP[0] = 1;
    for(int i=1;i<=N;i++){
        if(i&1)
            DP[i] = DP[i-1];
        else
            DP[i] = (DP[i-1] + DP[i/2])%MOD;
    }
    printf("%d\n",DP[N]);
    return 0;
}