#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <utility>
#include <sstream>
using namespace std;
#define MAX_V 101
int owner[MAX_V];
bool visited[MAX_V];
struct Loc{
    int x,y;
};
vector<Loc> people;
vector<Loc> taxi;
vector<int> a[MAX_V];
int AlternatingPath(int left){
    if(visited[left])  // to avoid cycling
        return 0;
    visited[left] = true;
    for (int j = 0; j < (int)a[left].size(); j++){
        int v = a[left][j];
        // either greedy assignment (if not assigned yet) or recurse
        if (owner[v] == -1 || AlternatingPath(owner[v])) {
            owner[v] = left;
            return 1;   // we found one matching
        }
    }
    return 0;   // no matching
}


int main()
{
    freopen("in","r",stdin);
    // freopen("out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        taxi.clear();
        people.clear();
        for(int i=0;i<n;i++) a[i].clear();
        for(int i=0;i<n;i++){
            Loc p;
            scanf("%d %d",&p.x,&p.y);
            people.push_back(p);
        }
        for(int i=0;i<m;i++){
            Loc p;
            scanf("%d %d",&p.x,&p.y);
            taxi.push_back(p);
        }
        for(int i=0;i<n;i++){
            Loc p1 = people[i];
            for(int j=0;j<m;j++){
                Loc p2 = taxi[j];
                if(abs(p1.x-p2.x)+abs(p1.y-p2.y)<=5){
                    a[i].push_back(1);
                }
                else{
                    a[i].push_back(0);
                }
            }
        }
        int cardinality = 0;
        memset(owner,-1,sizeof(owner));
        for(int left = 0;left < n;left++){
            memset(visited,false,sizeof(visited));
            cardinality += AlternatingPath(left);
        }
        printf("%d\n",cardinality);
    }
    return 0;
}