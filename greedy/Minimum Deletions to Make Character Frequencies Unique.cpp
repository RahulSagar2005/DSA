#include<bits/stdc++.h> 
using namespace std;
class Solution {
public:
    int minDeletions(string s) {
        int freq[26]={0};
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }
        unordered_set<int> st;
        int res=0;
        for(int i=0;i<s.size();i++){
            while(freq[i]>0 && st.find(freq[i])!=st.end()){
                freq[i]--;
                res++;
            }
            st.insert(freq[i]);
        }
        return res;
        
    }
}; 
// second approach 
class Solution {
public:
    int minDeletions(string s) {
        int freq[26]={0};
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }
        sort(begin(freq),end(freq));
        int res=0;
        for(int i=24;i>=0 && freq[i]>0;i--){
            if(freq[i]>=freq[i+1]){
                int prev=freq[i];
                freq[i]=max(freq[i+1]-1,0);
                res+=(prev-freq[i]);
            }
        }
        return res;
        
    }
};