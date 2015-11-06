//題意：跳格子，可以跳五步，把到過的六個位置變成
//思路：就....爆搜而已....
#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>
#include <queue>
#include <set>
#include <utility>
#include <map>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
const int dx[]={0,-1,0,1};
const int dy[]={-1,0,1,0};
int board[5][5];
int arr[6];
void DFS(int i,int j,int dep,set<int>& rec)
{
    arr[dep]=board[i][j];
    if(dep==5){
        int sum = 0;
        for(int i=0;i<6;i++)
            sum = sum*10 + arr[i];
        rec.insert(sum);
        return;
    }
    for(int k=0;k<4;k++){
        int nxt_i = i+dx[k];
        int nxt_j = j+dy[k];
        if(nxt_i>=0 && nxt_i < 5 && nxt_j>=0 && nxt_j < 5){
            
            DFS(nxt_i,nxt_j,dep+1,rec);
        }
    }
}


int main()
{   
    // freopen("in","r",stdin);
    set<int> rec;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            scanf("%d",&board[i][j]);
        }
    }
    memset(arr,0,sizeof(arr));
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            DFS(i,j,0,rec);
        }
    }
    printf("%lu\n",rec.size());
    return 0;
}