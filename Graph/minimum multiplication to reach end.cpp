#include<bits/stdc++.h>
using namespace std;    
    
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int,int>> pq;
        pq.push({start,0});
        vector<int> dist(100000,1e9);
        dist[start]=0;
        int mod=100000;
        while(!pq.empty()){
            int node=pq.front().first;
            int steps=pq.front().second;
            pq.pop();
            for(auto it:arr){
                int num=(it*node)%mod;
                if(steps+1<dist[num]){
                    dist[num]=steps+1;
                    if(num==end) return steps+1;
                    pq.push({num,steps+1});
                }
            }
        }
        return -1;
    }