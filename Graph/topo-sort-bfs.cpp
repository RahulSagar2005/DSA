#include<bits/stdc++.h>
using namespace std;
    vector<int> isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for(auto it: edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }
        vector<int> ind(V,0);
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                ind[it]++;
            }
        }
        vector<int> top;
        queue<int> q;
        for(int i=0;i<V;i++){
            if(ind[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            top.push_back(node);
            for(auto it: adj[node]){
                
                    ind[it]--;
                    if(ind[it]==0) q.push(it);
                
            }
        }
        return top;
    }
    