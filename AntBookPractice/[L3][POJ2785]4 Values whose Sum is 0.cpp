#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
#include <bitset>
#include <iostream>
using namespace std;
typedef long long int ll;

int main()
{   
    // freopen("in","r",stdin);
    ll n;
    while(~scanf("%lld",&n)){
        ll A[4005],B[4005],C[4005],D[4005];
        for(ll i=0;i<n;i++){
            ll a,b,c,d;
            scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
            A[i]=a,B[i]=b,C[i]=c,D[i]=d;
        }
        //enumerate A,B sum
        vector<ll> AB_sum;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                AB_sum.push_back(A[i]+B[j]);
            }  
        }
        sort(AB_sum.begin(),AB_sum.end());
        ll cnt = 0;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                ll CD_sum = -(C[i]+D[j]);
                cnt += upper_bound(AB_sum.begin(),AB_sum.end(),CD_sum) 
                    - lower_bound(AB_sum.begin(),AB_sum.end(),CD_sum);
            }
        }
        printf("%lld\n",cnt);
    }    
    return 0;
}