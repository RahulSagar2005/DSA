#include<bits/stdc++.h>
using namespace std;
// brute force
int lastStoneWeight(vector<int>& stones) {
        while(stones.size()>1){
            sort(stones.begin(),stones.end());
            int a=stones.back();stones.pop_back();
            int b=stones.back();stones.pop_back();
           stones.push_back(abs(a-b));
        }
        return stones[0]; 
}
// using heap 
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        while(pq.size()>1){
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            pq.push(abs(a-b));
        }
        return pq.top();
    }