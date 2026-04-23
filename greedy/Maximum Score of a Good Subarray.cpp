#include<bits/stdc++.h> 
using namespace std;
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int i=k;
        int j=k;
        int currmin=nums[k];
        int n=nums.size();
        int res=nums[k];
        while(i>0 || j<n-1){
            int leftval=(i>0)?nums[i-1]:0;
            int rightval=(j<n-1)?nums[j+1]:0;
            if(leftval>rightval){
                i--;
                currmin=min(currmin,nums[i]);
            }
            else{
                j++;
                currmin=min(currmin,nums[j]);
            }
            res=max(res,currmin*(j-i+1));
        }
        return res;
        
    }
};