//相當困難的線段樹題目
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <string>
#include <iostream>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
#define MAXN 1e9
#define PI 3.1415926536
int L[30005];
int S[30005],A[30005];
double prv[30005];

class segTree{
public:
    int N;
    vector<double> vx;
    vector<double> vy;
    vector<double> ang;

    segTree(int V){
        N = 1;
        while(N < V) 
            N *= 2;
        vx.resize(2*N-1,0);
        vy.resize(2*N-1,0);
        ang.resize(2*N-1,0);
    }
    //k是節點的標號,區間[l,r)
    void init(int k,int l,int r){
        ang[k] = vx[k] = 0.0;
        //是葉子
        if(r-l==1){
            vy[k] = L[l];
            return ;
        }
        else{
            int chl = k*2+1,chr = k*2+2;
            init(chl,l,(l+r)/2);
            init(chr,(l+r)/2,r);
            vy[k] = vy[chl] + vy[chr];
        }
    }
    // 線段s的角度變更了a
    // v是節點的編號,l和r是該節點對應的[l,r)
    void update(int p,double a,int v,int l,int r)
    {   
        // 要旋轉的線段s不會影響到這個節點範圍的向量
        if(p <= l || p >= r )
            return ;
        int chl = v*2+1,chr = v*2+2;
        int mid = (l+r)/2;
        update(p,a,chl,l,mid);
        update(p,a,chr,mid,r);
        //對於一個區間[l,r)的向量變化,是將他看成不變的[l,mid) 加 [mid,r)的變化,
        //所以當角度有要發生變化的線段s是位於當前區間mid後面的部分,
        //那只要將角度更改的工作交給[mid,r)這個區間即可。
        //而[l,r)這個區間則會在更新向量的時候藉由剛剛[mid,r)的角度更改
        //得出新的向量。
        //如果要變化的線段是位於mid之前,那表示[l,r)這個區間的角度當下就要更改
        if(p<=mid){
            ang[v] += a;
        }
        double s = sin(ang[v]), c = cos(ang[v]);
        vx[v] = vx[chl] + (c*vx[chr]-s*vy[chr]);
        vy[v] = vy[chl] + (s*vx[chr]+c*vy[chr]);
    }
};
int n,c;
int main()
{   
    // freopen("in","r",stdin);
    int cas=0;
    while(~scanf("%d %d",&n,&c)){
        if(cas++)
            printf("\n");
        for(int i=0;i<n;i++){
            scanf("%d",&L[i]);
            prv[i] = PI;
        }
        for(int i=0;i<c;i++){
            scanf("%d %d",&S[i],&A[i]);
        }
        segTree seg(n);
        seg.init(0,0,n);
        for(int i=0;i<c;i++){
            int s = S[i];
            double a = A[i]/360.0*2*PI;//角度轉弧度 , 360度 = 2PI弧度 , x度 = x/360*2PI弧度;
            seg.update(s,a-prv[s],0,0,n);
            prv[s] = a;
            printf("%.2lf %.2lf\n",seg.vx[0],seg.vy[0]);
        }
    }
    return 0;
}