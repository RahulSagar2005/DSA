#include<bits/stdc++.h>
using namespace std;
// approach 1 with max heap tc=o(n*n*log(k))
vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n=arr.size();
        priority_queue<pair<double,pair<int,int>>> pq;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                double frac=1.0*arr[i]/arr[j];
                pq.push({frac,{arr[i],arr[j]}});
                if(pq.size()>k){
                    pq.pop();
                }
            }
        }
        return {pq.top().second.first,pq.top().second.second};
    }
// using min heap 
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n=arr.size();
        priority_queue<pair<double,pair<int,int>>,vector<pair<double,pair<int,int>>>,greater<pair<double,pair<int,int>>>> pq;
        for(int i=0;i<n;i++){
            double frac=1.0*arr[i]/arr[n-1];
            pq.push({frac,{i,n-1}});
        }
        int small=1;
        while(small<k){
            auto it=pq.top();
            pq.pop();
            int i=it.second.first;
            int j=it.second.second-1;
            pq.push({1.0*arr[i]/arr[j],{i,j}});
            small++;
        }
        auto it=pq.top();
        return{arr[it.second.first],arr[it.second.second]};
    }