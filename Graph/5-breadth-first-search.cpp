#include<bits/stdc++.h>
using namespace std;
    vector<int> bfs(vector<vector<int>> &adj) {
        int n=adj.size();
        vector<int> vis(n,0);
        vis[0]=1;
        queue<int> q;
        q.push(0);
        vector<int> bfs;
        while(q.size()){
            int node=q.front();
            q.pop();
            bfs.push_back(node);
            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
