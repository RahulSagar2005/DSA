    #include<bits/stdc++.h>
    using namespace std;
    long long maxKelements(vector<int>& nums, int k) {
        long long out=0;
        priority_queue<int> pq(begin(nums),end(nums));
        while(k--){
            auto it=pq.top();
            pq.pop();
            out=out+it;   
            int in=(it+2)/3;   
            pq.push(in);
        }  
        return out;     
}
