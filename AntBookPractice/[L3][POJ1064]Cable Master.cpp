#include <cstdio>
#include <cstdlib>
#include <cmath>
#define EPS 1e-9
double cable[10005];

bool solve(double m,const int& N,const int& K)
{
    int cnt = 0;
    for(int i=0;i<N;i++){

        cnt += (int)(cable[i]/m);
    }
    return cnt >= K;
}

int main()
{   
    // freopen("in","r",stdin);
    int N,K;
    while(~scanf("%d%d",&N,&K)){
        for(int i=0;i<N;i++){
            double l;
            scanf("%lf",&l);
            cable[i]=l;
        }
        double lb = 0,ub = 100001,mid;
        while(fabs(ub-lb)>EPS){
            mid = (lb+ub)/2;
            if(solve(mid,N,K))
                lb = mid;
            else
                ub = mid;
        }
        printf("%.2lf\n",floor(ub*100)/100) ; //將小數點二位以下的部分無條件捨去
    }
    return 0;
}