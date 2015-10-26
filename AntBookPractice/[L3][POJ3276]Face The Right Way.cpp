//題意：給一列牛,有的面向前方有的面向後方,問最少的操作次數M以及翻轉區間K,使得牛全部朝向前方
//思路：直覺的方法就是,枚舉K,然後從左到右模擬翻轉的過程,判斷是否可以還有記錄操作次數,
//但這樣的複雜度是O(N*K^2)。有個方法能讓翻轉的複雜度降低,假如在第i個做翻轉,那他之後i+K-1個
//牛都會被反轉,用f來維護在哪些點發動過翻轉,這樣第j個牛只要看他前面j-K+1個區間的f值總合,就可
//以知道他的方向會不會改變(總和是偶數就等於沒變,因為轉過去又轉回來這樣)。

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int dir[5005];// Back 1,Forward 0
int f[5005];

int calc(const int& N,const int& K)
{
    // printf("K=%d\n",K);
    memset(f,0,sizeof(f));
    int cnt = 0;
    int sum = 0;//從i開始往前看i-K+1的合
    for(int i=0;i<=N-K;i++){
        if((dir[i]+sum)%2==1){ //Back就要轉向前
            cnt++;
            f[i]=1;
        }
        sum += f[i];
        if(i-K+1>=0)
            sum -= f[i-K+1];
    }
    //檢查剩下的[N-K+1,N) 牛有否都已forward
    for(int i=N-K+1;i<N;i++){
        if((dir[i]+sum)%2==1){
            return -1;
        }
        if(i-K+1>=0)
            sum -= f[i-K+1];
    }
    return cnt;
}

int main()
{   
    int N;
    while(~scanf("%d ",&N)){
        char s;
        for(int i=0;i<N;i++){
            scanf("%c ",&s);
            
            if(s=='B') dir[i] = 1;
            else dir[i] = 0;
        }
        int ansM = 1e6,ansK;
        for(int k=1;k<=N;k++){
            int res = calc(N,k);
            if(res!=-1 && res < ansM){
                ansM = res;
                ansK = k;
            }
        }
        printf("%d %d\n",ansK,ansM);
    }
    return 0;
}