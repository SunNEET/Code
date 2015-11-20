//標準解答加上註解的版本，原本的寫法因為要搶積分寫的很亂，不堪入目
//標程中對map的寫法很值得參考，可以讓邏輯更明確

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <bitset>
#include <map>
#include <iostream>
using namespace std;

map<int,vector<pair<int,int> > > weights; //y-x的值在哪些座標點出現
map<int,vector<int> > cnt; //統計指定的weight出現過幾次，同時記錄他的編號，後面還原用
pair<int,int> ans[100005]; 
vector<int> diag[100005]; 

int main()
{   
    // freopen("in","r",stdin);
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        int a, b;
        scanf("%d %d",&a,&b);
        //先預留空間給diag,之後會用來存x座標a對應的y值被標記成編號多少,所以y多大就要有幾個元素,預設全部標成0,代表沒有被標
        while (diag[a].size()<=b) 
            diag[a].push_back(0);
        weights[b-a].push_back(make_pair(a,b));
    }
    //將可以弄出特定y-x值的集合(weights之key值所對應的vector)，按照x座標(vector<pair<int,int> >的first)來將vector排序
    for(map<int,vector<pair<int,int> > >::iterator it = weights.begin();it!=weights.end();it++) {
        sort(it->second.begin(),it->second.end());
    }
    
    for(int i=0; i<n; i++) {
        int a;
        scanf("%d",&a);
        cnt[a].push_back(i);
    }

    for (map<int,vector<int> >::iterator v = cnt.begin();v!=cnt.end(); v++){
        //weights[v->first].size()代表,這個key值對應的vector有多少元素
        //這邊是判斷題目要的權重做不做得出來
        if(weights.count(v->first)==0||weights[v->first].size() != v->second.size()){
            printf("NO\n");
            return 0;
        }
        for(int i=0;i<v->second.size();i++){
            //對每個指定要求的weight都給他對應的,能做出該weight的座標
            ans[v->second[i]] = weights[v->first][i];
            //diag[x][y] = label,也就是維護該點實際上被標成幾號
            diag[weights[v->first][i].first][weights[v->first][i].second] = v->second[i];
        }
    }
    //檢查剛剛標完的label是否合法,對於每個(i,j),去檢查他正上方和正右邊的label有沒有比他小,比他小就不合法
    for (int i=0; i<100005; i++){
        for (int j=0; j<(int)diag[i].size(); j++){
            // 往右檢查
            if ((int)diag[i+1].size()-1>=j && diag[i+1][j]<diag[i][j]){
                printf("NO\n");
                return 0;
            }
            // 往上檢查
            if (j+1<=(int)diag[i].size()-1 && diag[i][j]>diag[i][j+1]){
                printf("NO\n");
                return 0;
            }
        }
    }
    puts("YES");
    for(int i=0;i<n;i++)
        printf("%d %d\n",ans[i].first,ans[i].second);

    return 0;
}