#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;

int adjMat[105][105];

int main()
{
	// freopen("in","r",stdin);
	int C,S,Q;
	int cas=1,BLK=0;
	while(scanf("%d%d%d",&C,&S,&Q)&&(C+S+Q)){
		if(BLK++)
			puts("");
		const int INF = INT_MAX>>2;
		for(int i=1;i<=C;i++)
			for(int j=1;j<=C;j++)
				adjMat[i][j]=INF;

		for(int i=0;i<S;i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			adjMat[u][v]=w;
			adjMat[v][u]=w;
		}
		
		for(int k=1;k<=C;k++){
			for(int i=1;i<=C;i++){
				for(int j=1;j<=C;j++){
					adjMat[i][j] = min(adjMat[i][j],max(adjMat[i][k],adjMat[k][j]));
				}
			}
		}
		printf("Case #%d\n",cas++);	
		for(int i=0;i<Q;i++){
			int u,v;
			scanf("%d %d",&u,&v);
			if(adjMat[u][v]==INF)
				puts("no path");
			else
				printf("%d\n",adjMat[u][v]);
		}
	}
	return 0;
}