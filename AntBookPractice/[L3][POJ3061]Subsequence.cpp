#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
int seq[100005];

int main()
{   
    // freopen("in","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        int N,S;
        scanf("%d%d",&N,&S);
        for(int i=0;i<N;i++)
            scanf("%d",&seq[i]);
        ll s=0,t=0,ans = N+1,sum=0;
        while(1){
            while(t < N && sum < S){
                sum += seq[t++];
            }
            if(sum < S) 
                break;
            ans = min(ans,t-s);
            sum -= seq[s++];
        }
        if(ans>N)
            ans = 0;
        printf("%lld\n",ans);
    }
    return 0;
}