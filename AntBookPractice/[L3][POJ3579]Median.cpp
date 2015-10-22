//題意：給你N個數字的數列,這些數字會產生CN_2(Cn取2)個差值,找出這些差值中的中位數
//思路：N有10^5次方,把N^2種組合算出來再排序需要的複雜度是O(N^2),會超時,所以用二分搜。
//先用二分搜去猜中位數m是多少,然後套用找第K大元素的做法,對已排序的序列在做一次二分搜O(nlogn),
//判斷是否 >= m 的差值個數,小於CN_2/2個,代表這個數字如果放在差值序列中會在中位數的右側。
//最後一個不滿足的左界lb即是中位數的數字（因為右界ub已經是最小的中位數右側的值）

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
ll X[100005];

bool solve(const int& N,const ll& CK_2,ll medium)
{
    int cnt = 0;
    for(int i=0;i<N;i++){
        cnt += X+N-lower_bound(X+i+1,X+N,X[i]+medium);
    }
    return cnt <= CK_2/2;
}
int main()
{   
    // freopen("in","r",stdin);
    // freopen("out","w",stdout);
    ll N;
    while(~scanf("%lld",&N)){
        ll _min=1e9,_max=0;
        ll CK_2 = (N*(N-1))/2;
        for(int i=0;i<N;i++){
            scanf("%lld",&X[i]);
        }
        sort(X,X+N);
        ll lb = 0,ub = X[N-1] - X[0],mid;
        while(ub-lb>1){
            mid = (ub+lb)/2;
            if(solve(N,CK_2,mid))
                ub = mid;
            else
                lb = mid;
        }
        printf("%lld\n",lb);
    }
    return 0;
}