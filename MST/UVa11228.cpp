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
using namespace std;
struct Point
{
    int x,y,index;
};
struct edge
{
    int u,v;
    double w;
};
bool operator< (const edge& a,const edge& b)
{
    return a.w < b.w;
}
vector<edge> ve;
vector<Point> vP;
int parent[100005],c;
int findSet(int u)
{
    if(parent[u]==u)
        return u;
    else
        return parent[u]=findSet(parent[u]);
}
void Union(int a,int b)
{
    int pa = findSet(a);
    int pb = findSet(b);
    if(pa!=pb){
        parent[pa] = pb;
    }
}
bool isSameSet(int a,int b)
{
    if(parent[a]==parent[b])
        return true;
    else
        return false;
}

int main()
{
    //freopen("in","r",stdin);
    int t,cnt=1;
    scanf("%d",&t);
    while(t--){
        vP.clear();
        ve.clear();
        int thres,x,y;
        scanf("%d %d",&c,&thres);
        for(int i=0;i<c;i++) parent[i]=i;
        for(int i=0;i<c;i++){
            Point p;
            scanf("%d %d",&x,&y);
            p.x = x; p.y = y; p.index=i;
            vP.push_back(p);
        }
        int E = vP.size()*vP.size();
        for(int i=0;i<vP.size()-1;i++){
            Point p1 = vP[i];
            for(int j=i+1;j<vP.size();j++){
                if(i!=j){
                    Point p2 = vP[j];
                    edge e;
                    e.u = p1.index;
                    e.v = p2.index;
                    e.w = sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
                    ve.push_back(e);
                }
            }
        }

        //O(ElogE)
        sort(ve.begin(),ve.end());

        int state=1;
        double mst_road=0,mst_rail=0;
        for(int i=0;i<ve.size();i++){
            edge e = ve[i];
            if(!isSameSet( findSet(e.u),findSet( (e.v)) )){
                Union(e.u,e.v);
                if(e.w>thres){
                    mst_rail += e.w;
                    state++;
                }
                else
                    mst_road += e.w;
            }
        }
        printf("Case #%d: %d %.0lf %.0lf\n",cnt++,state,mst_road,mst_rail);
    }
    return 0;
}