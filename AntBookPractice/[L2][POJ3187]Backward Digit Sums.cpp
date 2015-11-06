//題意：給出N跟sum,找出由1~N組成,能夠照巴斯卡三角型的累加規則往下加出sum的排列。
//ex : 3   1   2    4
//       4   3   6
//         7   9
//           16
//答案就是3 1 2 4
//思路：用next_permutation枚舉每種排列,然後看他形成的final sum是否等於sum。
//重點在於如何有效的做出final sum,直接模擬肯定會花太多時間,而觀察一下後可以發現,
//其實每個開始的數字,再加出Final sum的過程中被使用到的次數並不太一樣,所以我們換
//成思考,那每個數字他使用的次數有規律嗎？透過觀察,可以發現和巴斯卡三角型的第r列第k項
//一樣,所以讓起始數字乘上他在巴斯卡三角形所在的位置就好。

#include <cstdio>
#include <vector>
#include <algorithm>

int CN_K(int n, int k)
{
    int result = 1;
    for (int i = 0; i < k; ++i)
    {
        result = result * (n - i) / (i + 1);
    }
    return result;
}
bool solve(std::vector<int> num,const int n,const int sum)
{   
    int N = num.size();
    int res = 0;
    for(int i=0;i<n;i++){
        res += num[i]*CN_K(N-1,i);
    }
    return res == sum;
}
int main()
{   
    // freopen("in","r",stdin);
    int n,sum;
    while(~scanf("%d%d",&n,&sum)){
        std::vector<int> num;
        for(int i=1;i<=n;i++)
            num.push_back(i);
        do{
            if(solve(num,n,sum))
                break;
        }while(std::next_permutation(num.begin(),num.end()));
        
        for(int i=0;i<num.size();i++){
            if(i)
                printf(" ");
            printf("%d",num[i]);
        }
        puts("");
    }
    return 0;
}