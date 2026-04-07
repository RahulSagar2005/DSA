#include<bits/stdc++.h> 
using namespace std;
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n=tasks.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[tasks[i]]++;
        }
        int round=0;
        for(auto it:mp){
            int cnt=it.second;
            if(cnt==1){
                return -1;
            }
            if(cnt%3==0){
                round=round+(cnt/3);
            }
            else{
                round+=(cnt/3)+1;
            }
        }
        return round;    
    }
};