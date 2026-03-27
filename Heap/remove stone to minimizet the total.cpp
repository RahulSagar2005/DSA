    #include<bits/stdc++.h>
    using namespace std;
    int minStoneSum(vector<int>& piles, int k) {
        int n=piles.size();
        priority_queue<int> pq;// by default max heap
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=piles[i];
            pq.push(piles[i]);
        }
        for(int i=1;i<=k;i++){
            int max_el=pq.top();
            pq.pop();
            int rem=max_el/2;
            max_el-=rem;
            sum-=rem;
            pq.push(max_el);
        }
        return sum;  
    }