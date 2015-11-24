#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <iostream>
using namespace std;
typedef long long int ll;
ll m,h1,a1,h2,a2,x1,y1,x2,y2;
bool visited1[1000005],visited2[1000005];
bool loop1[1000005],loop2[1000005];
int main()
{   
    // freopen("in","r",stdin);
    scanf("%lld",&m);
    scanf("%lld%lld%lld%lld",&h1,&a1,&x1,&y1);
    scanf("%lld%lld%lld%lld",&h2,&a2,&x2,&y2);
    ll cnt1 = 0,cnt2 = 0,cyc1_cnt = 0,cyc2_cnt = 0;
    //find cnt for h1 -> a1
    for(int i=0;i<m;i++){
        visited1[h1]=1;
        if(h1==a1)
            break;
        h1 = (x1*h1+y1)%m;
        cnt1++;
    }
    //find loop a1 -> a1
    for(int i=0;i<m;i++){
        h1 = (x1*h1+y1)%m;
        loop1[h1]=1;
        cyc1_cnt++;
        if(h1==a1)
            break;
    }
    //find cnt for h2 -> a2
    for(int i=0;i<m;i++){
        visited2[h2]=1;
        if(h2==a2)
            break;
        h2 = (x2*h2+y2)%m;
        cnt2++; 
    }
    //find loop a2 -> a2
    for(int i=0;i<m;i++){
        h2 = (x2*h2+y2)%m;
        loop2[h2]=1;
        cyc2_cnt++;
        if(h2==a2)
            break;
    }
    //如果到不了a1或a2,必無解
    if(!visited2[a2] || !visited1[a1]){
        puts("-1");
        return 0;
    }
    //一開始到a1,a2 次數就一樣,直接輸出
    if(cnt1==cnt2){
        printf("%lld\n",cnt1);
        return 0;
    }
    //如果a1找不到循環節
    if(!loop1[a1]){
        for(int i=0;i<m;i++){
            if(cnt2 + cyc2_cnt*i == cnt1){
                printf("%lld\n",cnt1);
                return 0;
            }
        }
        puts("-1");
        return 0;
    }
    //如果a2找不到循環節
    if(!loop2[a2]){
        for(int i=0;i<m;i++){
            if(cnt1 + cyc1_cnt*i == cnt2){
                printf("%lld\n",cnt2);
                return 0;
            }
        }
        puts("-1");
        return 0;
    }
    //有循環節的情況下，要找cnt1+cyc1_cnt*x == cnt2+cyc2_cnt*y
    //移項後變成cnt1-cnt2+cyc1_cnt*x == cyc2_cnt*y
    //所以枚舉x,然後用cyc2_cnt去mod判斷能不能整除就好
    bool hasAns = false;
    ll ans ;
    for(int i=0;i<=m;i++){
        if(cnt1-cnt2+cyc1_cnt*i>=0 && (cnt1-cnt2+cyc1_cnt*i)%cyc2_cnt==0 ){
            hasAns = 1;
            ans = cnt1+cyc1_cnt*i;
            break;
        }
    }
    if(!hasAns)
        puts("-1");
    else
        printf("%lld\n",ans);

    return 0;
}