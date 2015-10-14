#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#define MAX_N 100005
using namespace std;
//在沒有超過目前左界前,一直找右邊最遠的
//如果線段已經開始超過原本的左界,就將剛剛的最遠右界定為左界,然後線段+1
typedef long long int ll;
struct line
{
    int x,y;
    line(int _x,int _y):x(_x),y(_y){}
};
int na,nb,a,b,l,r;
bool cmpLine(const line& a,const line& b)
{
    return a.x < b.x;
}
int countLine(const vector<line>& a,int n)
{
    int res = 0;
    int curLeft=l,curRight=INT_MIN;
    for(int i=0;i<n;i++){
        int ll = a[i].x;
        int rr = a[i].y;
        if(ll<=curLeft){ 
            curRight = max(curRight,rr);
            if(curRight>=r)
                return res+1;
        }
        else{ 
            curLeft = curRight;
            res++;
            if(ll<=curLeft){
                curRight = max(curRight,rr);
                if(curRight>=r)
                    return res+1;
            }
        }
    }
    if(curRight < r)
        return INT_MAX>>1;
    return res;
}
int main()
{   
    // freopen("in","r",stdin);
    while(~scanf("%d %d",&na,&nb)){
        vector<line> A,B;
        for(int i=0;i<na;i++){
            scanf("%d %d",&a,&b);
            A.push_back(line(a,b));
        }
        for(int i=0;i<nb;i++){
            scanf("%d %d",&a,&b);
            B.push_back(line(a,b));
        }
        scanf("%d %d",&l,&r);
        sort(A.begin(),A.end(),cmpLine);
        sort(B.begin(),B.end(),cmpLine);
        int cntA=0,cntB=0;
        cntA=countLine(A,na);
        cntB=countLine(B,nb);
        if(cntA==INT_MAX>>1&&cntB==INT_MAX>>1)
            puts("TIE");
        else if(cntA <= cntB)
            puts("A WIN");
        else
            puts("B WIN");
    }
    return 0;
}