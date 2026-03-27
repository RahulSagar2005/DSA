#include<bits/stdc++.h>
using namespace std;
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<pair<int,int>> adj[V];
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        set<pair<int,int>> st;
        vector<int>dist(V,1e9);
        dist[src]=0;
        st.insert({0,src});
        while(!st.empty()){
            auto it=*st.begin();
            int node=it.second;
            int dis=it.first;
            st.erase(it);
            if(dis>dist[node]) continue;
            for(auto it:adj[node]){
                int adjnode=it.first;
                int edw=it.second;
                if(dis+edw<dist[adjnode]){
                    dist[adjnode]=dis+edw;
                    st.insert({dis+edw,adjnode});
                }
            }
        }
        return dist;
    }