#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums) { 
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int res=0;
        for(auto &it:mp){
            int freq=it.second;
            if(freq==1){
                return -1;
            }
            res+=ceil((double)freq/3.0);
        }
        return res;
        
    }
};