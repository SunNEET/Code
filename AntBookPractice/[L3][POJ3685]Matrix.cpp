//題意：給出一個N*N的矩陣,第i項第j列的值為i^2 + 100000 × i + j^2 - 100000 × j + i × j
//求矩陣中的第M小元素
//思路：二分搜＋二分搜。第一層二分搜是判斷比 mid 小的元素數量有沒有超過M-1個,因為如果mid是第M小元素
//代表比他小的元素不會超過M-1個,可以想像一個排序過的由小到大的序列(0....M....N)裡,我們找到元素如果
//落在第0個~第M個的區間之間,就有機會是第M小元素,透過一直縮小左界和右界找到最後滿足條件的元素,便是第M
//個元素。第二層二分搜是因為他每一行由上往下的數值都有單調遞增性,所以可以直接將mid拿來在該行的數值中二
//分搜,直接找出mid可以插在哪一列,這表示在他之前的列的值都比他小,所以cnt+=lb_i(小於mid的元素數量)。

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll val(ll i,ll j){
    return i * i + 100000 * i + j * j - 100000 * j + i * j;
}

bool solve(const ll& N,const ll& M,ll m)
{
    ll cnt = 0;
    for(int j=1;j<=N;j++){
        ll lb_i = 0,ub_i = N+1,mid_i,test;
        while(ub_i-lb_i>1){
            mid_i = (lb_i+ub_i)/2;
            if(val(mid_i,j) < m)
                lb_i = mid_i;
            else
                ub_i = mid_i;
        }
        cnt += lb_i;
    }
    return cnt <= M-1;
}

int main()
{   
    freopen("in","r",stdin);
    // freopen("out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        ll N,M;
        scanf("%lld%lld",&N,&M);
        ll lb = -1e12,ub = 1e12,mid;
        while(ub - lb >1){
            mid = (lb+ub)/2;

            if(solve(N,M,mid))
                lb = mid;
            else
                ub = mid;
        }
        printf("%lld\n",lb);
    }
    return 0;
}