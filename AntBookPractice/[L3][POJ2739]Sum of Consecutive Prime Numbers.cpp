//題意：給出一個數字,求有多少種連續的質數數列總和等於該數字
//思路：就.....爬行法,反正加到爆了就停,然後扣開頭,loop
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <map>
#include <vector>
#include <algorithm>
// using namespace std;

std::bitset<10005> bs;
std::vector<int> sieve()
{  
    std::vector<int> res;
    bs.set();
    int ub = 10005;
    bs[0]=bs[1]=0;
    for(int i=2;i<=ub;i++){
        if(bs[i]){
            for(int j=i*i;j<=ub;j+=i){
                bs[j]=0;
            }
            res.push_back(i);
        }
    }
    return res;
}
int main()
{   
    // freopen("in","r",stdin);
    // freopen("out","w",stdout);
    std::vector<int> primes = sieve();
    int n,np=(int)primes.size();
    while(scanf("%d",&n)&&n){
        int sum=0,l=0,r=0,ans=0;
        while(1){
            while(r < np && sum < n){
                sum += primes[r++];
            }
            if(sum < n)
                break;
            if(sum == n)
                ans++;
            sum -= primes[l++];
        }
        printf("%d\n",ans);
    }
    return 0;
}