// 題意：字串S長M，由N個小寫字母構成。欲通過增刪字母將其變為回文串，增刪特定字母花費不同，求最小花費。

// 思路：區間DP。另DP[i][j] := Si....Sj變成回文所需的成本,可以將回文花費整理出幾種情況：
// 1. Si == Sj , DP[i][j] = DP[i+1][j-1]
// 2. remove Si from front, DP[i][j] = DP[i+1][j] + del[i]
// 3. Add Si to end,(Si==Sj+1) DP[i][j] = DP[i+1][j] + add[i]
// 4. remove Sj from end, DP[i][j] = DP[i][j-1] + del[j]
// 5. Add Sj to front,(Si-1==Sj ) DP[i][j] = DP[i][j-1] + add[j]
// 要注意的是，可以發現如果這次要操作的是Si的刪除或追加,就相當於不用考慮最外面的字元Si,
// 而只需去考慮Si+1.....Sj的值,所以追加或刪除我只要挑成本最低的方式就必定會最好,Sj同理。
// 所以能將式子壓縮成 => DP[i][j] = min(DP[i+1][j]+cost[i],DP[i][j-1]+cost[j]);

// 註：因為i,j需要的值來自(i+1,j)跟(i,j-1),相當於表格上的左邊跟下面,所以會需要斜著填表。
// 或著是像google出來一整票的大陸寫法,將i從m-1到0這樣反著填回來。
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <bitset>
#include <map>
#include <iostream>
using namespace std;

int DP[3001][3001];//DP[i][j] := Si....Sj變成回文所需的成本

int main()
{   
    // freopen("in","r",stdin);
    // freopen("out","w",stdout);
    int n,m;
    int cost[32];
    scanf("%d%d",&n,&m);
    string str;
    cin >> str;
    for(int i=0;i<m;i++){
        char c;
        int add,del;
        scanf("%s%d%d",&c,&add,&del);
        cost[c-'a'] = min(add,del);
    }
    

    for(int i=0;i<m;i++)
        DP[i][i] = 0;

    for(int k=0;k<=str.length()-2;k++){
        for(int i=0,j=i+1+k;j<str.length();i++,j++){
            DP[i][j] = min(DP[i+1][j]+cost[str[i]-'a'],DP[i][j-1]+cost[str[j]-'a']);
            if(str[i]==str[j])
                DP[i][j] = min(DP[i][j],DP[i+1][j-1]);
        }
    }

    printf("%d\n",DP[0][m-1]);

    return 0;
}