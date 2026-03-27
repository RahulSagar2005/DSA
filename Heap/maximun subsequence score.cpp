    #include<bits/stdc++.h>
    using namespace std;
    // dp approach    
    int k;
    int n;
    priority_queue<int,vector<int>,greater<int>> pq;
    map<tuple<int,int,int>,long long> dp;
    void removefrompq(int nums2){
        vector<int> temp;
        while(!pq.empty()){
            int el=pq.top();
            pq.pop();
            if(el==nums2){
                break;
            }
            temp.push_back(el);
        }
        for(int i=0;i<temp.size();i++){
            pq.push(temp[i]);
        }
    }
    long long solve(vector<int>& nums1, vector<int>& nums2,int sum,int cmin,int i,int cnt){
        if(cnt==k){
            return sum*cmin;
        }
        if(i>=n){
            return 0;
        }
        auto key=make_tuple(i,cnt,cmin);
        if(dp.count(key)) return dp[key];
        pq.push(nums2[i]);
        int kmin=min(cmin,pq.top());
        long long take=solve(nums1,nums2,sum+nums1[i],kmin,i+1,cnt+1);
        removefrompq(nums2[i]);
        long long not_take=solve(nums1,nums2,sum,cmin,i+1,cnt);
        return dp[key]=max(take,not_take);
    }
    
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        k=k;
        n=nums1.size();
        return solve(nums1,nums2,0,INT_MAX,0,0);
    }
// priority queue approach
long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> vec;
        int n=nums1.size();
        for(int i=0;i<n;i++){
            vec.push_back({nums1[i],nums2[i]});
        }
        priority_queue<int,vector<int>,greater<int>> pq;
        auto lambda=[&](auto &p1,auto &p2){
            return p1.second>p2.second;
        };
        long long ksum=0;
        sort(vec.begin(),vec.end(),lambda);
        for(int i=0;i<=k-1;i++){
            ksum+=vec[i].first;
            pq.push(vec[i].first);
        }
        long long result=ksum*vec[k-1].second;
        for(int i=k;i<n;i++){
            ksum+=vec[i].first-pq.top();
            pq.pop();
            pq.push(vec[i].first);
            result=max(result,ksum*vec[i].second);
            
        }
        return result;

    }