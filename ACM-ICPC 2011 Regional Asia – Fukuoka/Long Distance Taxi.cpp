#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <utility>
#include <climits>
using namespace std;
#define INF INT_MAX>>2
int N,M,cap;
struct edge{
	int v,w;
	edge(int _v,int _w):v(_v),w(_w){

	}
};
struct loc{
	int d,v,cap;
	loc(int _d,int _v,int _cap):d(_d),v(_v),cap(_cap){}
	bool operator>(const loc& other)const{
		return d > other.d;
	}
};
vector<edge> adj[6005];
priority_queue<loc,vector<loc>,greater<loc> > pq;
bool hasGas[6005];
int res,noCnt;
int dist[6005][2005];
void dijkstra(int s)
{
	for(int i=0;i<noCnt;i++)
		for(int j=0;j<=cap;j++) 
			dist[i][j] = INF;
	dist[s][cap] = 0;
	pq.push(loc(0,s,cap));
	while(!pq.empty()){
		loc front = pq.top(); pq.pop();
		int d = front.d;
		int u = front.v;
		int cur_cap = front.cap;
		for(int j=0;j<adj[u].size();j++){
			edge e = adj[u][j];
			if(cur_cap - e.w >=0){
				//到加油站,油量回滿
				if(hasGas[e.v]){
					if(dist[u][cur_cap]+e.w < dist[e.v][cap]){
						dist[e.v][cap] = dist[u][cur_cap]+e.w;
						pq.push(loc(dist[e.v][cur_cap-e.w],e.v,cap));
					}
				}
				else{
					if(dist[u][cur_cap] + e.w < dist[e.v][cur_cap-e.w]){
						dist[e.v][cur_cap-e.w] = dist[u][cur_cap] + e.w;
						pq.push(loc(dist[e.v][cur_cap-e.w],e.v,cur_cap-e.w));
					}
				}
			}
		}
	}
}

int main()
{
	// freopen("5854.in","r",stdin);
	// freopen("5854.out","w",stdout);
	while(scanf("%d%d%d ",&N,&M,&cap) && (N+M+cap)){
		for(int i=0;i<6005;i++) adj[i].clear();
		cap*=10;
		noCnt=0;
		map<string,int> no;
		string start,end;
		cin >> start >> end;
		string p1,p2;
		int u,v,w;
		for(int i=0;i<N;i++){
			cin >> p1 >> p2;
			if(no.find(p1)==no.end())
				no[p1]=noCnt++;
			if(no.find(p2)==no.end())
				no[p2]=noCnt++;
			u = no[p1]; v = no[p2];
			scanf("%d ",&w);
			adj[u].push_back(edge(v,w));
			adj[v].push_back(edge(u,w));
		}
		memset(hasGas,0,sizeof(hasGas));
		string gasName;
		for(int i=0;i<M;i++){
			cin >> gasName;
			hasGas[no[gasName]]=true;
		}
		int s = no[start],t = no[end];
		
		int ans = INF ;
		dijkstra(s);
		for(int j=0;j<=cap;j++){
			ans = min(ans,dist[t][j]);
		}
		if(ans==INF)
			puts("-1");
		else
			printf("%d\n",ans);
	}

	return 0;
}