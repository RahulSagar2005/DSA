#include<bits/stdc++.h>
using namespace std;
// brute force 
typedef long long ll;
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<ll> result(n,0);
        for(int i=0;i<n;i++){
            priority_queue<int,vector<int>,greater<int>> pq;
            for(int j=0;j<n;j++){
                if(nums1[i]>nums1[j]){
                    pq.push(nums2[j]);
                    if(pq.size()>k){
                        pq.pop();
                    }
                }
            }
            long long sum=0;
            while(!pq.empty()){
                sum+=pq.top();
                pq.pop();
            }
            result[i]=sum;
        }
        return result;
    }
// priority queue approach 
vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<vector<int>>  vec;
        vector<ll> result(n,0);
        for(int i=0;i<n;i++){
            vec.push_back({nums1[i],i,nums2[i]});
        }
        sort(vec.begin(),vec.end());
        ll sum=0;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++){
            if(i>0 && vec[i-1][0]==vec[i][0]){
                ll ans=result[vec[i-1][1]];
                result[vec[i][1]]=ans;
            }
            else{
            result[vec[i][1]]=sum;
            }
            pq.push(vec[i][2]);
            sum+=vec[i][2];
            if(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }
        }
        return result;
    }