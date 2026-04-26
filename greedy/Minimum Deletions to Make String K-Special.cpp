#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26,0);
        for(char &c:word){
            freq[c-'a']++;
        }
        int res=word.length();
        for(int i=0;i<26;i++){
            int del=0;
            for(int j=0;j<26;j++){
                if(i==j) continue;
                if(freq[j]<freq[i]){
                    del+=freq[j];
                }
                else if(abs(freq[j]-freq[i])>k){
                    del+=abs(freq[j]-freq[i]-k);
                }
                
            }
            res=min(res,del);
        } 
        return res;       
    }
};
// 2nd approach 
class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26,0);
        for(char &c:word){
            freq[c-'a']++;
        }
        int res=word.length();
        sort(freq.begin(),freq.end());
        int cumsum=0;
        for(int i=0;i<26;i++){
            int del=cumsum;
            for(int j=25;j>i;j--){
                if(freq[j]-freq[i]<=k){
                    break;
                }
                del+=freq[j]-freq[i]-k;
            }
            res=min(res,del);
            cumsum+=freq[i];
        } 
        return res;       
    }
};