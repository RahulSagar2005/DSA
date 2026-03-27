#include<bits/stdc++.h>
using namespace std;
vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int,int>> adj[n+1];
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<int>dist(n+1,1e9);
        vector<int> parent(n+1);
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> pq;
        for(int i=1;i<=n;i++) parent[i]=i;
        dist[1]=0;
        pq.push({0,1});
        while(!pq.empty()){
            int node=pq.top().second;
            int dis=pq.top().first;
            pq.pop();
            if(dis>dist[node]) continue;
            for(auto it:adj[node]){
                int adjnode=it.first;
                int edw=it.second;
                if(dis+edw<dist[adjnode]){
                    dist[adjnode]=dis+edw;
                    pq.push({dis+edw,adjnode});
                    parent[adjnode]=node;
                    
                }
            }
        }
        if(dist[n]==1e9) return {-1};
        vector<int> path;
            int node = n;
            
            while(parent[node] != node){
                path.push_back(node);
                node = parent[node];
            }
            
            path.push_back(1);
            reverse(path.begin(), path.end());
            
            path.insert(path.begin(), dist[n]);   // add total distance
            
            return path;
    }