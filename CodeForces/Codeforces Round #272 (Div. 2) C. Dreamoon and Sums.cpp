// 作法：令d = div(x,b), m = mod(x,b) , 帶回原式推出 d = m*k
// 將d帶入原式 x = b*d + m 推得 x = m(b*k+1)
// 接下來直接預處理將可能的答案累加起來,因為 m 屬於[1,b-1]
// 所以 x = 1(b*k+1),2(b*k+1),......,(b-1)(b*k+1)
// 將所有可行的 x 加起來 = b(b-1)/2(k*b+1)
// 再來因為 k 屬於[1,a]
// 用同樣的道理推得所有可行x的最後累加值為b(b-1)/2((a*(a+1)/2*b+a)

//註：對於這種要MOD的題目還是不太會掌握MOD該放哪些地方。
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;
#define MOD 1000000007
typedef long long ll;

int main()
{   
    // freopen("in","r",stdin);
    ll a,b;
    scanf("%lld%lld",&a,&b);
    ll p1 = ((b*(b-1)))/2%MOD;
    ll p2 = ((a*(a+1)))/2%MOD;
    p2 = ((p2*b))%MOD;
    p2 = ((p2+a))%MOD;
    ll ans = ((p1*p2)+MOD)%MOD;
    printf("%lld\n",ans);
    return 0;
}