// 題意：奶牛Bessie在0~N時間段產奶。農夫約翰有M個時間段可以擠奶，時間段f,t內Bessie能擠到的牛奶量e。
// 奶牛產奶後需要休息R小時才能繼續下一次產奶，求Bessie最大的擠奶量。

// 思路：DP[i]代表第i個時間區段擠奶能夠得到的最大值,所以要把前面i-1個時間區段都掃過一遍,
// 對於pre.end + R <= cur.start的區段,就表示可以擠奶,用前面所算出的最大值加上區段i擠奶
// 的數值。

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <bitset>
#include <iostream>
using namespace std;
typedef long long int ll;

struct interval{
    ll start,end,eff;
    interval(ll _start,ll _end,ll _eff):start(_start),end(_end),eff(_eff){}
    bool operator < (const interval& other)const{
        return start < other.start;
    }
};

int main()
{   
    // freopen("in","r",stdin);
    ll N,M,R;
    ll DP[1000005];//DP[i] := 第i個時間區間擠奶能夠得到的最大值
    scanf("%lld%lld%lld",&N,&M,&R);
    vector<interval> vInterval;
    int start,end,eff;
    for(int i=0;i<M;i++){
        scanf("%d%d%d",&start,&end,&eff);
        vInterval.push_back(interval(start,end,eff));
    }
    sort(vInterval.begin(),vInterval.end());
    // DP[0] = 0 ; 
    //對第i個時間段,比較他前面全部的i-1個時間段,判斷能否擠奶並比較最大值
    for(int i=1;i<=M;i++){
        interval cur = vInterval[i-1];
        DP[i] = cur.eff;
        for(int j=1;j<=i-1;j++){
            interval pre = vInterval[j-1];
            if(pre.end + R <= cur.start ){
                DP[i] = max(DP[i],DP[j]+ cur.eff );
            }
        }
    }
    ll ans = 0;
    for(int i=1;i<=M;i++)
        ans = max(ans,DP[i]);
    printf("%lld\n",ans);
    return 0;
}