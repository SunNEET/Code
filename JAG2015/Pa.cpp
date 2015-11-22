#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
 
int main()
{   
    // freopen("in","r",stdin);
    string s1,s2;
    cin >> s1 >> s2;
    bool sw = 1;
    string tmp = "";
    int p1=0,p2=0;
    bool haveAns = false;
    for(int i=0;i<s1.length();i++){
        if(p1>=s1.length() || p2>=s2.length())
            break;
        if(sw){
            if(s1[p1]==s1[i]){
                tmp += s1[p1];
                p1++;
            }
            else{
                while(s1[p1]!=s1[i] && p1 < s1.length()){
                    p1++;
                }
                if(p1 < s1.length() && s1[p1]==s1[i]){
                    tmp += s1[p1];
                    p1++;
                }
            }
            sw = !sw;
        }
        else{
            if(s2[p2]==s1[i]){
                tmp += s2[p2];
                p2++;
            }
            else{
                while(s2[p2]!=s1[i] && p2 < s2.length()){
                    p2++;
                }
                if(p2 < s2.length() && s2[p2]==s1[i]){
                    tmp += s2[p2];
                    p2++;
                }
            }
            sw = !sw;
        }
    }
    // cout << p1 << " " << p2 << endl;    
    // cout << tmp << endl;
    if(s1 == tmp)
        haveAns = true;
    sw = 1;
    p1 = 0,p2 = 0;
    tmp = "";
    for(int i=0;i<s1.length();i++){
        if(p1>=s1.length() || p2>=s2.length())
            break;
        if(!sw){
            if(s1[p1]==s1[i]){
                tmp += s1[p1];
                p1++;
            }
            else{
                while(s1[p1]!=s1[i] && p1 < s1.length()){
                    p1++;
                }
                if(p1 < s1.length() && s1[p1]==s1[i]){
                    tmp += s1[p1];
                    p1++;
                }
            }
            sw = !sw;
        }
        else{
            if(s2[p2]==s1[i]){
                tmp += s2[p2];
                p2++;
            }
            else{
                while(s2[p2]!=s1[i] && p2 < s2.length()){
                    p2++;
                }
                if(p2 < s2.length() && s2[p2]==s1[i]){
                    tmp += s2[p2];
                    p2++;
                }
            }
            sw = !sw;
        }
    }
    if(s1 == tmp)
        puts("Yes");
    else if(haveAns)
        puts("Yes");
    else
        puts("No");
 
    return 0;
}