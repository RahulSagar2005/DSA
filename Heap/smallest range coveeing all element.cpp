#include<bits/stdc++.h>
using namespace std;
vector<int> smallestRange(vector<vector<int>>& nums) {
        int k=nums.size();
        vector<int> vec(k,0);
        vector<int> resrange={-1000000,1000000};
        while(true){
        int minel=INT_MAX;
        int maxel=INT_MIN;
        int minelind=-1;
        
        for(int i=0;i<k;i++){
            int listind=i;
            int elind=vec[i];
            int el=nums[listind][elind];
            if(el<minel){
                minel=el;
                minelind=listind;
            }
            maxel=max(maxel,el);
        }
        if(maxel-minel<resrange[1]-resrange[0]){
            resrange[1]=maxel;
            resrange[0]=minel;
        }
        int nextind=vec[minelind]+1;
        if(nextind>=nums[minelind].size()){
            break;
        }
        vec[minelind]=nextind;
        }
        return resrange;   
}
// using heap
vector<int> smallestRange(vector<vector<int>>& nums) {
        int k=nums.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<int> resrange={-1000000,1000000};
        int maxel=INT_MIN;
        for(int i=0;i<k;i++){
            pq.push({nums[i][0],i,0});
            maxel=max(maxel,nums[i][0]);
        }
        while(!pq.empty()){
            vector<int> curr=pq.top();
            pq.pop();
            int minel=curr[0];
            int listind=curr[1];
            int idx=curr[2];
            if(maxel-minel<resrange[1]-resrange[0]){
                resrange[1]=maxel;
                resrange[0]=minel;
            }
            if(idx+1<nums[listind].size()){
                int nextel=nums[listind][idx+1];
                pq.push({nextel,listind,idx+1});
                maxel=max(maxel,nextel);
            }
            else{
                break;
            }
        }
        return resrange;
    }