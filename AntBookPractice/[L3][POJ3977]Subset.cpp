//題意：給出一組數字,輸出總和最小的非空子集合的值,並輸出子集合大小,若有多組解,輸出最小的子集合。
//思路：折半完全枚舉。先枚舉一半的所有sum值可能性並存到map，然後再剩下那一半用新的sum的負值(-sum)
//去對先前的map做二分搜,找出兩者相加會最小的位置。因為sum對二分搜出來的iterator前面的值或當下的值
//不能確定哪個加起來會比較小,所以都要試試看(只要不是開頭)。這題寫法前前後後修了很多次,原本再開一個
//map來存後半段+前半枚舉的最佳解,結果TLE......雖說lower_bound是O(logN),不過可能因為數字真的太
//大,多餘的呼叫太多次還是會導致超時。所以改成每次枚舉後半段的值就只在乎他是不是最小的子集合和最少的次
//數。
#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>
#include <set>
#include <utility>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
ll ll_abs(const ll& x)
{
    return x >= 0 ? x : -x;
}
int main()
{   
    // freopen("in","r",stdin);
    ll n;
    while(scanf("%lld",&n) &&n){
        ll a[40];
        for(int i=0;i<n;i++){
            ll val;
            scanf("%lld",&val);
            a[i] = val;
        }

        map<ll,int> pre;
        pair<ll,int> final(ll_abs(a[0]),1);
        for(int i=0;i<(1<<(n/2));i++){
            ll sum = 0;
            int cnt=0;
            for(int j=0;j<n/2;j++){
                if(i>>j&1){
                    sum += a[j];
                    cnt++;
                }
            }
            if(cnt==0)  continue;
            ll abs_sum = ll_abs(sum);
            final = min(final,make_pair(abs_sum,cnt));
            map<ll,int>::iterator it = pre.find(sum);
            if(it!=pre.end()){
                pre[sum] = min(it->second,cnt);
            }
            else{
                pre[sum] = cnt;
            }
        }
        for(int i=0;i<1<<(n-n/2);i++){
            ll sum = 0;
            int cnt=0;
            for(int j=0;j<(n-n/2);j++){
                if(i>>j&1){
                    sum += a[j+n/2];
                    cnt++;
                }
            }
            if(cnt==0)  continue;
            ll abs_sum = ll_abs(sum);
            final = min(final,make_pair(abs_sum,cnt));
            map<ll,int>::iterator it = pre.lower_bound(-sum);
            if(it != pre.end()){
                ll val = ll_abs(sum + it->first);
                final = min(final,make_pair(val,it->second+cnt));
            }
            if(it != pre.begin()){
                it--;
                ll val = ll_abs(sum + it->first);
                final = min(final,make_pair(val,it->second+cnt));
            }
        }
        printf("%lld %d\n",final.first,final.second);
    }
    return 0;
}