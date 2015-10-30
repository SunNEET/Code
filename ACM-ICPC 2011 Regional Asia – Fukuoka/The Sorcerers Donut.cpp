#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


#define MAX_N 11
#define MAX_M 21
int n,m,si,sj;
char table[MAX_N][MAX_M];
//向上
void DFS1(int i,int j,int dep,string& s)
{
	if(dep==n)
		return ;
	s += table[i][j];
	if(i==0)
		DFS1(n-1,j,dep+1,s);
	else
		DFS1(i-1,j,dep+1,s);
	return;
}
// 向右上
void DFS2(int i,int j,int dep,string& s)
{
	if(dep>0 && i== si && j==sj)
		return ;
	s += table[i][j];
	int nxt_i=i-1,nxt_j=j+1;
	if(nxt_i == -1)
		nxt_i = n-1;
	if(nxt_j == m)
		nxt_j = 0;
	DFS2(nxt_i,nxt_j,dep+1,s);
}
//向右
void DFS3(int i,int j,int dep,string& s)
{
	if(dep==m)
		return ;
	s += table[i][j];
	if(j==m-1)
		DFS3(i,0,dep+1,s);
	else
		DFS3(i,j+1,dep+1,s);
	return;
}
//向右下
void DFS4(int i,int j,int dep,string& s)
{
	if(dep>0 && i== si && j==sj)
		return ;
	s += table[i][j];
	int nxt_i=i+1,nxt_j=j+1;
	if(nxt_i == n)
		nxt_i = 0;
	if(nxt_j == m)
		nxt_j = 0;
	DFS4(nxt_i,nxt_j,dep+1,s);
}
//向下
void DFS5(int i,int j,int dep,string& s)
{
	if(dep==n)
		return ;
	s += table[i][j];
	if(i==n-1)
		DFS5(0,j,dep+1,s);
	else
		DFS5(i+1,j,dep+1,s);
	return;
}
//左下
void DFS6(int i,int j,int dep,string& s)
{
	if(dep>0 && i== si && j==sj)
		return ;
	s += table[i][j];
	int nxt_i=i+1,nxt_j=j-1;
	if(nxt_i == n)
		nxt_i = 0;
	if(nxt_j == -1)
		nxt_j = m-1;
	DFS6(nxt_i,nxt_j,dep+1,s);
}
//向左
void DFS7(int i,int j,int dep,string& s)
{
	if(dep==m)
		return ;
	s += table[i][j];
	if(j==0)
		DFS7(i,m-1,dep+1,s);
	else
		DFS7(i,j-1,dep+1,s);
	return;
}
//左上
void DFS8(int i,int j,int dep,string& s)
{
	if(dep>0 && i== si && j==sj)
		return ;
	s += table[i][j];
	int nxt_i=i-1,nxt_j=j-1;
	if(nxt_i == -1)
		nxt_i = n-1;
	if(nxt_j == -1)
		nxt_j = m-1;
	DFS8(nxt_i,nxt_j,dep+1,s);
}
int main()
{
	// freopen("in","r",stdin);
	while(scanf("%d%d ",&n,&m)&&(n+m)){
		memset(table,0,sizeof(table));
		for(int i=0;i<n;i++){
			scanf("%s",table[i]);
		}
		// for(int i=0;i<n;i++){
		// 	printf("%s\n",table[i]);
		// }
		vector<string> totalStr;
		string s;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				si=i,sj=j;
				s="";
				DFS1(i,j,0,s);
				totalStr.push_back(s);
				s="";
				DFS2(i,j,0,s);
				totalStr.push_back(s);
				s="";
				DFS3(i,j,0,s);
				totalStr.push_back(s);
				s="";
				DFS4(i,j,0,s);
				totalStr.push_back(s);
				s="";
				DFS5(i,j,0,s);
				totalStr.push_back(s);
				s="";
				DFS6(i,j,0,s);
				totalStr.push_back(s);
				s="";
				DFS7(i,j,0,s);
				totalStr.push_back(s);
				s="";
				DFS8(i,j,0,s);
				totalStr.push_back(s);
			}
		}
		sort(totalStr.begin(),totalStr.end());
		int Max = 1;
		string ans ;
		for(int i=0;i+1<totalStr.size();i++){
			string s1 = totalStr[i];
			string s2 = totalStr[i+1];
			bool isOK=true;
			for(int j=0;j<min(s1.length(),s2.length())&&isOK;j++){
				if(s1[j]!=s2[j]){
					if(j-1>Max){
						// cout << "s1:" << s1 << endl;
						// cout << "s2:" << s2 << endl;
						Max = j-1;
						ans = s1.substr(0,j);
					}
					isOK = false;
				}
			}
			if(isOK){
				if(s1.length() < s2.length() && s1.length() > Max){
					Max = s1.length();
					ans = s1;
				}
				else if(s1.length() >= s2.length() && s2.length() > Max){
					Max = s2.length();
					ans = s2;
				}
			}
		}
		if(Max==1)
			puts("0");
		else
			cout << ans << endl;
	}
	return 0;
}
