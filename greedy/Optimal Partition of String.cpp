#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int partitionString(string s) { 
        int n=s.size();
        vector<int> lastseen(26,-1);
        int cnt=0;
        int substringstart=0;
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(lastseen[ch-'a']>=substringstart){
                cnt++;
                substringstart=i;
            }
            lastseen[ch-'a']=i;
        }
        return cnt+1;
    }
};