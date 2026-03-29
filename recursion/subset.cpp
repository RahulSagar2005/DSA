#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> res;
    void solve(int i,vector<int>& nums,vector<int> &temp){
        if(i>=nums.size()){
            res.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(i+1,nums,temp);
        temp.pop_back();
        solve(i+1,nums,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
    int i=0;
    vector<int> temp;
    solve(i,nums,temp);
    return res;
    }
};