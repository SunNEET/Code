//題意：隨意組合給定的數字,組出兩組,求絕對值最小的差
//思路：這題略坑，012的這種情況並不是看成12，而是直接不存在。還有，原本我用
//String做next_permutation()，會TLE，就算加入偶數特判重複計算也一樣。看
//了一下別人說好像string做排列會比較慢....改成vector還真的秒過。

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

int main()
{   
    // freopen("in","r",stdin);
    int t;
    scanf("%d ",&t);
    while(t--){
        string s;
        stringstream ss;
        int n;
        getline(cin,s);
        ss << s;
        vector<int> digits;
        while(ss >> n){
            digits.push_back(n);
        }
        sort(digits.begin(),digits.end());
        int len = digits.size();
        int ans = 1e8;
        do{
            int n_pre = 0,n_post=0;
            if(len&1){
                if(len/2+1!=1 && digits[0]==0) continue;
                if(len-(len/2+1)!=1 && digits[len/2+1]==0) continue;
                for(int i=0;i<len/2+1;i++)
                    n_pre = n_pre*10 + digits[i];
                for(int i=len/2+1;i<len;i++)
                    n_post = n_post*10 + digits[i]; 
            }
            else{
                if(len/2!=1 && digits[0]==0) continue;
                if(len-(len/2)!=1 && digits[len/2]==0) continue;
                
                for(int i=0;i<len/2;i++)
                    n_pre = n_pre*10 + digits[i];
                for(int i=len/2;i<len;i++)
                    n_post = n_post*10 + digits[i]; 
            }
            // cout<<n_pre<<" "<<n_post<<endl;
            ans = min(ans,abs(n_pre-n_post));
        }while(next_permutation(digits.begin(),digits.end()));
        printf("%d\n",ans);   
    }
    return 0;
}