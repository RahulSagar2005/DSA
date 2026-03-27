# include<bits/stdc++.h>
using namespace std;
    bool canFinish(int V, vector<vector<int>>& prerequisties) {
        vector<vector<int>> adj(V);
        for(auto it:prerequisties){
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
        vector<int> topo;
        queue<int> q;
        for(int i=0;i<V;i++){
            if(ind[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();

            topo.push_back(node);
            for(auto it: adj[node]){
                
                    ind[it]--;
                    if(ind[it]==0) q.push(it);
                
            }
        }
        if(topo.size()==V) return true;
        else return false;
    }