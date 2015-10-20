//題意：從數列中找出一段連續數列,使該區間和的絕對值最接近T,並輸出該連續數列的上下界
//思路：一樣用爬行法,但原本的數列缺乏單調性,無法判斷往右移動的r是否已經達l開始所能做到的最佳解.
//所以先求出前綴和,再將其排序,如此一來往右移動時加出的解只要接近T,便可以保證是以l為左(or右)界時,
//能夠做出的最佳解。排序後的前綴數列下標,對應原本的a為[min(i,j)+1,max(i,j)]
//註：此題SpecialJudge怪怪的,即使取的區間不同但sum一樣,應該也是對才是,但我改拿最後出現過的
//最接近區間上下界就AC了
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long int ll;
int a[100005];
struct prefix{
    int val,id;
    prefix(){}
    bool operator < (const prefix& b)const{
        return val < b.val;
    }
};
prefix pre[100005];

int main()
{   
    // freopen("in","r",stdin);
    // freopen("out","w",stdout);
    int n,k;
    while(scanf("%d%d",&n,&k)&&(n+k)){
        memset(pre,0,sizeof(pre));
        pre[0].val = 0;
        pre[0].id = 0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            pre[i].id = i;
            pre[i].val += a[i] + pre[i-1].val;
        }
        sort(pre,pre+n+1);
        for(int i=0;i<k;i++){
            ll T;
            scanf("%lld",&T);
            ll s=0,t=1,sum=0,min_diff = 1e9,ans_sum=0,ansl=0,ansr=0;
            while(t<=n){
                sum = llabs(pre[t].val - pre[s].val);
                // printf("sum=%d\n",sum);
                if(llabs(sum-T)<=min_diff){
                    min_diff = llabs(sum-T);
                    ans_sum = sum;
                    ansl = min(pre[s].id,pre[t].id)+1;
                    ansr = max(pre[s].id,pre[t].id);
                }
                if(sum < T || s == t-1)
                    t++;
                else
                    s++;
            }
            printf("%lld %lld %lld\n",ans_sum,ansl,ansr);
        }
    }
    return 0;
}