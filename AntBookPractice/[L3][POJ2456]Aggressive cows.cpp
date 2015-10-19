#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
ull stall[100005];

bool solve(const int& N,const int& C,ull x)
{
    int cnt = 1;
    ll pre = stall[0];
    for(int i=1;i<N;i++){
        if(stall[i] - pre >= x){
            pre = stall[i];
            cnt++;
        }
    }
    return cnt >= C;
}

int main()
{   
    // freopen("in","r",stdin);
    int N,C;
    while(~scanf("%d%d",&N,&C)){
        memset(stall,0,sizeof(stall));
        ull p;
        for(int i=0;i<N;i++){
            scanf("%llu",&p);
            stall[i]=p;
        }
        ull lb = 0,ub = 1e9+1,mid;
        sort(stall,stall+N);
        while(ub-lb>1){
            mid = (lb+ub)/2;
            if(solve(N,C,mid))
                lb = mid;
            else
                ub = mid;
        }
        printf("%llu\n",lb);
    }
    return 0;
}