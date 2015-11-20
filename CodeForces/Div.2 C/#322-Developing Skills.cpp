// 題意：求出(技能點數+K個配額點數)/10(無條件捨去),能得到的最大加總

// 做法：先從最能湊到10的倍數的開始給k,效益最大。所以根據個位數來排序,
// 只要k還足夠把它填到10的倍數就填給他。之後判斷k剩多少，是足夠把剩下
// 的數字都填滿 還是 只能增加k/10。


#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;
typedef long long ll;

bool cmp_1(const int& a,const int& b)
{
    return (a%10)>(b%10);
}
int main()
{   
    // freopen("in","r",stdin);
    ll n,k;
    scanf("%lld%lld",&n,&k);
    ll a[100005];
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
    sort(a,a+n,cmp_1);
    for(int i=0;i<n;i++){
        int dec1 = a[i]%10;
        if(dec1!=0 && k >= (10-dec1)){
            a[i] += (10-dec1);
            k -= (10-dec1);
        }
    }
    ll bonus = 0;
    // k remains
    if(k>0){
        ll sum = 0;
        for(int i=0;i<n;i++){
            ll res = 100-a[i];
            bonus += (res/10);
            sum += res;
        }
        if(k < sum){
            ll add = k/10;
            bonus = add;
        }
    }
    //sum up
    ll ans = 0;
    double tmp;
    for(int i=0;i<n;i++){
        tmp = floor(1.0*a[i]/10);
        ans += (int)tmp;
    }
    printf("%lld\n",ans + bonus);
    return 0;
}