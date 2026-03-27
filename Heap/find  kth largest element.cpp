#include<bits/stdc++.h>
using namespace std;
// usinh min heap with size=k
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
    }
// using sorting
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),greater<>());
        return nums[k-1];
    }