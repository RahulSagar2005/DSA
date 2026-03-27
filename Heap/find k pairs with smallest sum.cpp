#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,pair<int,int>>>pq;
        int n=nums1.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<nums2.size();j++){
                long long sum=nums1[i]+nums2[j];
                if(pq.size()<k){
                    pq.push({sum,{i,j}});
                }
                else if(pq.top().first>sum){
                    pq.pop();
                    pq.push({sum,{i,j}});
                }
                else{
                    break;// i=7 j=4 pq.top()=10  discard this sum=11 also i=7,j=6 sum=13
                }
            }
        }
        vector<vector<int>> res;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int i=it.second.first;
            
            int j=it.second.second;
            res.push_back({nums1[i],nums2[j]});
        }
        return res;
    }
// optimal approach 
vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        int n=nums1.size();
        int m=nums2.size();
        int sum=nums1[0]+nums2[0];
        vector<vector<int>> res;
        set<pair<int,int>> st;
        pq.push({sum,{0,0}});
        st.insert({0,0});
        while(k-- && !pq.empty()){
            auto it=pq.top();
            pq.pop();
            int i=it.second.first;
            int j=it.second.second;
            res.push_back({nums1[i],nums2[j]});
            // push({i+1,j})
            if(i+1<n && st.find({i+1,j})==st.end()){
                pq.push({nums1[i+1]+nums2[j],{i+1,j}});
                st.insert({i+1,j});
            }
            if(j+1<m && st.find({i,j+1})==st.end()){
                pq.push({nums1[i]+nums2[j+1],{i,j+1}});
                st.insert({i,j+1});
            }
        }
        return res;
    }