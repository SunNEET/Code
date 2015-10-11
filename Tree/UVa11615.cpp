#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>
#include <climits>
#include <queue>
#include <map>
#include <cmath>
#include <sstream>
#include <bitset>
using namespace std;

int getLevel(int a) //find the highest bit 1
{
    int ans;
    for(int i=0;i<22;i++)
        if((a>>i)&1)
            ans=i;
    return ans;
}
int main()
{   
    // freopen("in","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        int n,a,b;
        scanf("%d%d%d",&n,&a,&b);
        int total = (1<<n)-1;//2^n-1
        int la = getLevel(a)+1;
        int lb = getLevel(b)+1;
        if(la > lb)
            total-=((1<<(n-la+1))-1);
        else
            total-=((1<<(n-lb+1))-1);
        total+=1;
        printf("%d\n",total);
    }
    return 0;
}
