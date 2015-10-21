//題意：n次考試,每次bi題里答對ai題,可以不計k次成績,求最大的W=100*sigam(ai)/sigma(bi)
//思路：二分搜找答案,數學式可以移項加加減減後變成100*(sigma(ai)-sigma(bi)*W)>=0
//而成績可以放掉k個不計,換句話說取a[i]-b[i]*W最大的n-k個即可,如果這幾個都加不出滿足的數值,
//那去取其他更小的也不可能。
//註：精度超坑...最後看標準解答有把小數點後一位四捨五入,照著做才過
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <map>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define EPS 1e-9
int a[1005],b[1005];
double y[1005];
bool solve(const int& n,const int& k,double x)
{
    for(int i=0;i<n;i++)
        y[i] = a[i]-b[i]*x;

    sort(y,y+n);
    reverse(y,y+n);
    double sum=0.0;
    for(int i=0;i<n-k;i++){
        sum += 100*y[i];
    }
    return sum >= x;
}

int main()
{   
    // freopen("in","r",stdin);
    // freopen("out","w",stdout);
    int n,k;
    while(scanf("%d%d",&n,&k) && (n+k)){
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<n;i++)
            scanf("%d",&b[i]);
        double lb = 0,ub = 1e9,mid;
        while(fabs(lb-ub)>EPS){
            mid = (lb+ub)/2;
            if(solve(n,k,mid))
                lb = mid;
            else
                ub = mid;
        }
        printf("%d\n",(int)(lb*100+0.5));
    }
    return 0;
}