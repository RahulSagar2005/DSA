#include<bits/stdc++.h>
using namespace std;
// without using min heap
long long findScore(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>> vec;
        for(int i=0;i<n;i++){
            vec.push_back({nums[i],i});
        }
        sort(vec.begin(),vec.end());
        long long score=0;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            int ele=vec[i].first;
            int idx=vec[i].second;
            if(vis[idx]==false)
            {
                vis[idx]=true;
                score=score+ele;
                if(idx-1>=0 && vis[idx-1]==false){
                    vis[idx-1]=true;
                }
                if(idx+1<n && vis[idx+1]==false){
                    vis[idx+1]=true;
                }
            }   
        }
        return score;
}
// using heap
long long findScore(vector<int>& nums) {
        int n=nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        vector<bool> vis(n,false);
        long long score=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int el=it.first;
            int idx=it.second;
            if(vis[idx]==false){
                vis[idx]=true;
                score=score+el;
                if(idx-1>=0 && vis[idx-1]==false){
                    vis[idx-1]=true;
                }
                if(idx+1<n && vis[idx+1]==false){
                    vis[idx+1]=true;
                }
            }
        }
        return score;
    }