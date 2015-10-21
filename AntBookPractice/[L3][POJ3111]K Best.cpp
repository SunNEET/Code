//題意：給出N個物品的Vi和Wi,挑選K個物品使得 Vi的總和/Wi的總和 最大,輸出這K個物品
//思路：移項變換數學式,二分搜找最大值的時候,排序完就是物品取用的順序,輸出前K個就是解。

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
#define EPS 1e-6
struct item{
    double CP;  int id;
    bool operator < (const item& b)const{
        return CP > b.CP;
    }
};
int v[100005],w[100005];
item s[100005];
bool solve(const int& n,const int& k,double x)
{
    for(int i=0;i<n;i++){
        s[i].CP = v[i]-x*w[i];
        s[i].id = i;
    }
    sort(s,s+n);
    double sumW=0.0,sumV=0.0;
    for(int i=0;i<k;i++){
        int id = s[i].id;
        sumW += w[id];
        sumV += v[id];
    }
    return sumV/sumW >= x;
}


int main()
{   
    // freopen("in","r",stdin);
    // freopen("out","w",stdout);
    int n,k;
    while(~scanf("%d%d",&n,&k)){
        for(int i=0;i<n;i++)
            scanf("%d%d",&v[i],&w[i]);
        memset(s,0,sizeof(s));
        double lb = 0,ub = 1e6,mid;
        for(int i=0;i<50;i++){
            mid = (lb+ub)/2;
            if(solve(n,k,mid))
                lb = mid;
            else
                ub = mid;
        }
        
        for(int i=0;i<k;i++){
            if(i)
                printf(" ");
            printf("%d",s[i].id+1);
        }
        printf("\n");
    }
    return 0;
}