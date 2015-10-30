#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <climits>
#include <bitset>
#include <algorithm>
using namespace std;
typedef unsigned long long int ull;
int b[25],n,num;
int cost[15][15];//字串i往後面接字串j多出來的長度
int dp[15][1<<15]; //dp[i][mask]->在有mask裡這些字串的情況下,能獲得的最短長度
vector<string> vs;
void build_fail(const string& P)
{
	int i=0,j=-1;
	b[0]=-1;
	while(i<P.length()){
		while(j>=0 && P[i]!=P[j]){
			j = b[j];
		}
		i++; j++;
		b[i] = j;
	}
}
int kmpSearch(const string& T,const string& P)
{
	// cout << "T:" << T << " "<<"P:"<<P<<endl;
	int i=0,j=-1;
	while(i < T.length()){
		while(j>=0 && T[i]!=P[j]){
			j = b[j];
		}
		i++;j++;
		if(j==P.length()){
			return j;//判斷匹配結束前最多有幾個相同的字母
			j = b[j];
		}
	}
	return j;//判斷匹配結束前最多有幾個相同的字母
}
int TSP(int at,ull mask){
	if(mask==(1<<num)-1)
		return 0;
	if(dp[at][mask])
		return dp[at][mask];
	int ans = INT_MAX>>1;
	int cst;
	for(int j=0;j<num;j++){
		if(cost[at][j]!=-1 &&(mask & (1<<j))==0 ){
			cst = TSP(j,mask|(1<<j))+cost[at][j];
			ans = min(ans,cst);
		}
	}
	return dp[at][mask]=ans;
}
int main()
{
	// freopen("in","r",stdin);
	while(scanf("%d ",&n)&&n){
		string s;
		vector<string> tmp;
		for(int i=0;i<n;i++){
			cin >> s;
			tmp.push_back(s);
		}
		vs.clear();
		for(int i=0;i<n;i++){
			bool overlap=false;
			for(int j=0;j<n;j++){
				if(i!=j && tmp[j].find(tmp[i])!=string::npos){
					overlap=true;
					break;
				}
			}
			if(!overlap)
				vs.push_back(tmp[i]);
		}
		num = vs.size();
		memset(dp,0,sizeof(dp));
		for(int i=0;i<num;i++){
			for(int j=0;j<num;j++){
				if(i!=j){
					build_fail(vs[j]);
					int same_num = kmpSearch(vs[i],vs[j]);
					cost[i][j] = vs[j].length() - same_num;
				}
				else
					cost[i][i] = -1;
			}
		}
		// for(int i=0;i<num;i++){
		// 	for(int j=0;j<num;j++){
		// 		printf("cost[%d][%d]=%d\n",i,j,cost[i][j]);
		// 	}
		// }
		int ans = INT_MAX>>1;
		for(int i=0;i<num;i++)
			ans = min(ans,(TSP(i,1<<i)+(int)vs[i].length()));
		printf("%d\n",ans);
	}
	return 0;
}