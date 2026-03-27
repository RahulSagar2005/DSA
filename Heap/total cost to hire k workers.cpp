#include<bits/stdc++.h>
using namespace std;
 long totalCost(vector<int>& nums, int k, int cand) {
        int n=nums.size();
        int i=0;
        int j=n-1;
        long long ans=0;
        int hired=0;
        priority_queue<int,vector<int>,greater<int>> pq1;
        priority_queue<int,vector<int>,greater<int>> pq2;
        while(hired<k){
        while(pq1.size()<cand && i<=j){
            pq1.push(nums[i]);i++;
        }
        while(pq2.size()<cand && j>=i){
            pq2.push(nums[j]);j--;
        }
        int minpq1=pq1.size()>0?pq1.top():INT_MAX;
        int minpq2=pq2.size()>0?pq2.top():INT_MAX;
        if(minpq1<=minpq2){
            ans+=pq1.top();
            pq1.pop();
        }
        else{
            ans+=pq2.top();
            pq2.pop();
        }
        hired++;
        }
        return ans;
    }