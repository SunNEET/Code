//題意：給出一個整數集合,要從中挑四個不同元素且滿足a+b+c=d的子集合,求最大的d
//思路：最陽春的思路就是枚舉三個數字相加出來的所有總和,然後將總和排序後,從最大的數字開始對總和
//的陣列二分搜,看有沒有解。但這題n有1000,所以O(N^3)理論上會爆(不過看大陸人討論好像沒爆...測資太水),
//必須轉換思路,將等式改成a+b=d-c,這麼一來就可以用O(N^2)枚舉所有的a,b總和,然後用枚舉d-c對排序過的
//總和做二分搜。為了判斷是不是拿到同一個元素做出來的sum或dif,特別寫了一個結構存他是用哪兩個元素的。
#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <vector>
#include <set>
#include <utility>
#include <map>
#include <algorithm>
#include <bitset>
#include <iostream>
using namespace std;
typedef long long int ll;

struct half{
    ll val;
    int n1,n2;
    half(ll _val,int _n1,int _n2):val(_val),n1(_n1),n2(_n2){}
    bool operator<(const half& other)const{
        return val < other.val;
    }
    bool operator>(const half& other)const{
        return val > other.val;
    }
    bool operator==(const half& other)const{
        return val == other.val;
    }
};

int main()
{   
    // freopen("in","r",stdin);
    ll n;
    while(scanf("%lld",&n)&&n){
        ll num;
        ll a[1005];
        for(int i=0;i<n;i++){
            scanf("%lld",&num);
            a[i]=num;
        }
        vector<half> ab_sum;
        for(int i=0;i+1<n;i++){
            for(int j=i+1;j<n;j++){
                ll sum = a[i]+a[j];//A+B
                ab_sum.push_back(half(sum,i,j));
            }
        }
        vector<half> dc_dif;
        for(int i=0;i+1<n;i++){
            for(int j=i+1;j<n;j++){
                ll dif1 = a[j]-a[i];//D-C
                ll dif2 = a[i]-a[j];//D-C
                dc_dif.push_back(half(dif1,j,i));
                dc_dif.push_back(half(dif2,i,j));
            }
        }
        sort(ab_sum.begin(),ab_sum.end());
        ll d = -1;
        for(int i=0;i<dc_dif.size();i++){
            half dcdif = dc_dif[i];
            vector<half>::iterator it1,it2;
            it1 = lower_bound(ab_sum.begin(),ab_sum.end(),dcdif);
            it2 = upper_bound(ab_sum.begin(),ab_sum.end(),dcdif);
            if(it1 == ab_sum.end())
                continue;
            if(it1->val==dcdif.val && it1->n1 != dcdif.n1 && it1->n1 != dcdif.n2 && it1->n2 != dcdif.n1 && it1->n2 != dcdif.n2)
                d = max(d,a[dcdif.n1]);
            else{
                while(it1 != it2){
                    it1++;
                    if(it1->val==dcdif.val && it1->n1 != dcdif.n1 && it1->n1 != dcdif.n2 && it1->n2 != dcdif.n1 && it1->n2 != dcdif.n2)
                        d = max(d,a[dcdif.n1]);
                }
            }
        }
        if(d == -1)
            puts("no solution");
        else
            printf("%lld\n",d);
    }
    return 0;
}