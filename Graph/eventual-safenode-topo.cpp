# include<bits/stdc++.h>
using namespace std;
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
            for(auto it:edges){
                int u=it[0];
                int v=it[1];
                adj[u].push_back(v);
            }
            vector<int> ind(V,0);
            vector<vector<int>> adjrev(V);
            for(int i=0;i<V;i++){
                for(auto it:adj[i]){
                    adjrev[it].push_back(i);
                    ind[i]++;
                }
            }
            queue<int> q;
            vector<int> safenode;
            for(int i=0;i<V;i++){
                if(ind[i]==0) q.push(i);
            }
            while(!q.empty()){
                int node=q.front();
                q.pop();
                safenode.push_back(node);
                for(auto it:adjrev[node]){
                    ind[it]--;
                    if(ind[it]==0) q.push(it);
                }
            }
            sort(safenode.begin(),safenode.end());
            return safenode;
            
    }