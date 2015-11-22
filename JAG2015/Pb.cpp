#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <iostream>
using namespace std;
typedef long long int ll;

string s;
bool used[15];
ll len,num,ans,maxDif,ten;
void DFS(int dep,ll cur)
{
    if(dep==len){
        ll ab = llabs(cur-num);
        ll dif = min(ab,ten-ab);
        if(dif > maxDif){
            maxDif = dif;
            ans = cur;
        }
        else if(dif == maxDif && cur < ans)
            ans = cur;
        return;
    }
    for(int i=0;i<=9;i++){
        if(used[i])
            continue;
        used[i]=true;
        DFS(dep+1,cur*10+i);
        used[i]=false;
    }
    return ;
}

int main()
{   
    // freopen("in","r",stdin);
    cin >> s;
    //init
    ten = 1;
    len = s.length();
    for(int i=0;i<len;i++) 
        ten*=10;
    maxDif = 0;
    ans = 1e12;
    memset(used,0,sizeof(used));
    num = 0;
    sscanf(s.c_str(),"%lld",&num);
    //find ANS
    DFS(0,0);
    if(ans < ten/10)
        printf("0");
    printf("%lld\n",ans);

    return 0;
}