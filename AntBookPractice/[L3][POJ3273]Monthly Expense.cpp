//題意：給出一個序列,要將他切成M段並且最小化每段中的最大值
//思路：因為要連續,所以直接累加到超過上限看成一段,只要不超過M段都表示有解

#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll val[100005];

bool solve(const int& N,const int& M,const ll& x)
{
    ll spd = 0,cnt=0;
    for(int i=0;i<N;i++){
        if(val[i]>x)
            return false;
        spd += val[i];
        if(spd>x){
            cnt++;
            spd = val[i];
        }
    }
    cnt++;
    return cnt<=M;
}
int main()
{   
    // freopen("in","r",stdin);
    int N,M;
    while(~scanf("%d%d",&N,&M)){
        for(int i=0;i<N;i++)
            scanf("%lld",&val[i]);
        ll lb = 0,ub = 1e9+1,mid;
        while(ub-lb>1){
            mid = (ub+lb)/2;
            if(solve(N,M,mid))
                ub = mid;
            else
                lb = mid;
        }
        printf("%lld\n",ub);
    }
    return 0;
}