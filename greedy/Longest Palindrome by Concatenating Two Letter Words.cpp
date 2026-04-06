#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mp;
        int n=words.size();
        for(int i=0;i<n;i++){
            mp[words[i]]++;
        }
        bool inmiddle=false;
        int result=0;
        for(int i=0;i<n;i++){
            string rev=words[i];
            reverse(begin(rev),end(rev));
            if(rev!=words[i]){
                if(mp[rev]>0 && mp[words[i]]>0){
                    mp[rev]--;
                    mp[words[i]]--;
                    result+=4;
                }
            }
            else{
                if(mp[words[i]]>=2){
                    mp[words[i]]-=2;
                    result+=4;
                }
                else if(mp[words[i]]==1 && inmiddle==false){
                    mp[words[i]]--;
                    inmiddle=true;
                    result+=2;
                }
            }
        }
        return result;
    }
};