#include<bits/stdc++.h>
using namespace std;
// using min heap
vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto it:mpp){
            pq.push({it.second,it.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> result;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            result.push_back(it.second);
        }
        return result;
    }
// apprach 2 using bucket sort 
vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        vector<vector<int>> bucket(n+1);
        for(auto it:mpp){
            int element=it.first;
            int freq=it.second;
            bucket[freq].push_back(element);
        }
        vector<int> result;
        for(int i=n;i>=0;i--){
            if(bucket[i].size()==0) continue;
            while(bucket[i].size()>0 && k>0){
                result.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
        }
        return result;
    }