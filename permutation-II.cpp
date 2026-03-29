    #include<bits/stdc++.h>
    using namespace std;
    vector<vector<int>> res;
    void solve( unordered_map<int,int> &mp,vector<int> temp,int n){
        if(temp.size()==n){
            res.push_back(temp);
            return;
        }
        for(auto &it:mp){
            if(it.second==0) continue;
            temp.push_back(it.first);
            it.second--;
            solve(mp,temp,n);
            temp.pop_back();
            it.second++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        vector<int> temp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        solve(mp,temp,n);
        return res;
    }

// better approach 
class Solution {
public:
    vector<vector<int>> res;
    void solve(vector<int> &nums,int idx,int n){
        if(idx>=n){
            res.push_back(nums);
            return;
        }
        unordered_set<int> mp;
        for(int i=idx;i<n;i++){
            if(mp.find(nums[i])!=mp.end()){
                continue;
            }
            mp.insert(nums[i]);
            swap(nums[i],nums[idx]);
            solve(nums,idx+1,n);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        int idx=0;
        solve(nums,idx,n);
        return res;
    }
};