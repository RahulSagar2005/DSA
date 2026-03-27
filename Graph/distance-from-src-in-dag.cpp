# include<bits/stdc++.h>
using namespace std;
 void toposort(int node,
                  vector<pair<int,int>> adj[],
                  vector<int> &vis,
                  stack<int> &st) {

        vis[node] = 1;

        for(auto it : adj[node]) {
            if(!vis[it.first]) {
                toposort(it.first, adj, vis, st);
            }
        }

        st.push(node);
    }

    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {

        vector<pair<int,int>> adj[V];

        // Build adjacency list
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
        }

        stack<int> st;
        vector<int> vis(V, 0);

        // Topological Sort
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                toposort(i, adj, vis, st);
            }
        }

        vector<int> dist(V, INT_MAX);
        dist[0] = 0;

        // Relax edges in topo order
        while(!st.empty()){
            int node = st.top();
            st.pop();

            if(dist[node] != INT_MAX){
                for(auto it : adj[node]){
                    int v = it.first;
                    int wt = it.second;

                    if(dist[node] + wt < dist[v]){
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }

        // Replace unreachable with -1
        for(int i = 0; i < V; i++){
            if(dist[i] == INT_MAX)
                dist[i] = -1;
        }

        return dist;
    }