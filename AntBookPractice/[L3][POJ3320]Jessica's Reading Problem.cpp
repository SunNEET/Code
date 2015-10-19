#include <cstdio>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int a[1000005];

int main()
{   
    // freopen("in","r",stdin);
    int n;
    while(~scanf("%d",&n)){
        set<int> all;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            all.insert(a[i]);
        }
        int var = all.size();
        int s=0,t=0,num=0;
        map<int,int> cnt;
        int res = n;
        while(1){
            while(t < n && num < var){
                if(cnt[a[t++]]++==0)
                    num++;
            }
            if(num < var) break;
            res = min(res,t-s);
            if(--cnt[a[s++]]==0)
                num--;
        }
        printf("%d\n",res);
    }

    return 0;
}