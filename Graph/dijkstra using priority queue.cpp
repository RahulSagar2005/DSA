#include<bits/stdc++.h>
using namespace std;
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<pair<int,int>> adj[V];
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> pq;
        vector<int>dist(V,1e9);
        pq.push({0,src});
        dist[src]=0;
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(dis>dist[node]) continue;
            for(auto it:adj[node]){
                int adjnode=it.first;
                int edw=it.second;
                if(dis+edw<dist[adjnode]){
                    dist[adjnode]=edw+dis;
                    pq.push({dis+edw,adjnode});
                }
            }
        }
        return dist;
    }