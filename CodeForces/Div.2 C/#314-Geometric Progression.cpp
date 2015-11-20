// 題意：求出所有長度為三,公比為k的子序列


// 做法：考慮每個元素當中間值的情況,等於我們只需要去考慮他左邊比他小的k1個元素
// 和右邊比他大的k2個元素,k1*k2就是以該元素為子序列中間值時能組出的等比序列。
// 實作上用兩個map來維護,一個存在該元素右邊的元素有哪些,另一個存左邊的元素有哪些
// 因為是從0開始迭代,所以一開始只有右邊的map,之後每做完一次判斷就會將中間的元素
// 加入左邊的map裡

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;
#define MOD 1000000007
typedef long long ll;


ll a[200005];


int main()
{   
    // freopen("in","r",stdin);
    int n,k;
    scanf("%d%d",&n,&k);
    map<ll,ll> left,right;
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
        right[a[i]]++;
    }
    ll ans = 0,cnt_r,cnt_l;
    for(int i=0;i<n;i++){
        right[a[i]]--;
        cnt_r = right[a[i]*k];
        if(a[i]%k==0){
            cnt_l = left[a[i]/k];
            ans += cnt_r*cnt_l;
        }
        left[a[i]]++;
    }
    printf("%lld\n",ans);
    return 0;
}