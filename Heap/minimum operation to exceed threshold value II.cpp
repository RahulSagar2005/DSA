 #include<bits/stdc++.h>
 using namespace std;
 int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long >,greater<long long>> pq(begin(nums),end(nums));
        int cnt=0;
        while(!pq.empty()&& pq.top()<k)
        {
  
            long long s1=pq.top(); pq.pop();
            long long s2=pq.top(); pq.pop();
            long long news1=min(s1,s2)*2+ max(s1,s2);
            pq.push(news1);
            cnt++;

        } 
        return cnt;   
    }