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
typedef long long ll;
typedef pair<int,int> pii;
int n;
string s;
bool R(int x)
{
    int now = x,ll = x,rr = x; //ll目前往左走到哪,rr目前往右走到哪
    while(now>=0 && now<n){
        if(s[now]=='<'){
            now = ll-1;
            ll--;
        }
        else{
            now = rr+1;
            rr++;
        }
    }
    //左邊走出去
    if(now < 0)
        return false;
    //右邊走出去
    return true;
}
int moveCnt(int x)
{
    int now = x,ll = x,rr = x; //ll:=目前往左走到哪,rr:=目前往右走到哪
    int len = s.length();
    while(now>=0 && now<n){
        if(s[now]=='<'){
            now = ll-1;
            ll--;
        }
        else{
            now = rr+1;
            rr++;
        }
    }
    //左邊走出去
    if(now < 0)
        return rr+1; //最右側走到哪
    //右邊走出去
    return len-ll; //最左側走到哪
}

int main()
{   
    // freopen("in","r",stdin);
    scanf("%d ",&n);
    cin >> s;
    int lb = 0,ub = n-1;
    while(ub-lb>1){
        int x = (lb+ub)/2;
        if(R(x))
            ub = x;
        else
            lb = x;
    }
    int mv_r = moveCnt(ub);
    int mv_l = moveCnt(lb);
    printf("%d\n",max(mv_l,mv_r));
    return 0;
}