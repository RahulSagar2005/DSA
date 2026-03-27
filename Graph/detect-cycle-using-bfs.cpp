# include<bits/stdc++.h>
using namespace std;
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // using bfs 
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
        int cnt=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;
            top.push_back(node);
            for(auto it: adj[node]){
                
                    ind[it]--;
                    if(ind[it]==0) q.push(it);
                
            }
        }
        if(cnt==V) return false ;
        else return true;
    }