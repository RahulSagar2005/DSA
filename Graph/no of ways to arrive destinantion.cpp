# include<bits/stdc++.h>
using namespace std;
int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        vector<long long> dist(n,LLONG_MAX),ways(n,0);
        dist[0]=0;
        ways[0]=1;
        pq.push({0,0});
        int mod=(1e9+7);
        while(!pq.empty()){
            int node=pq.top().second;
            long long dis=pq.top().first;
            pq.pop();
            for(auto it:adj[node]){
                int adjnode=it.first;
                int edw=it.second;
                if(dis+edw<dist[adjnode]){
                    dist[adjnode]=dis+edw;
                    pq.push({dis+edw,adjnode});
                    ways[adjnode]=ways[node];

                }
                else if(dis+edw==dist[adjnode]){
                    ways[adjnode]=(ways[node]+ways[adjnode])%mod;
                }
            }
        }
        return ways[n-1];
    }