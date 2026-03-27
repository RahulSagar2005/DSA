#include<bits/stdc++.h>
using namespace std;
  void dfs(int node,vector<int> adj[],vector<int>&vis,stack<int> &st){
      vis[node]=1;
      for(auto it:adj[node]){
          if(!vis[it]){
              dfs(it,adj,vis,st);
          }
      }
      st.push(node);
  }
    void dfs3(int node,vector<int> adjt[],vector<int> &vis){
      vis[node]=1;
      for(auto it:adjt[node]){
          if(!vis[it]){
              dfs3(it,adjt,vis);
          }
      }
  }
    int kosaraju(int V, vector<vector<int>> &edges) {
        vector<int> vis(V,0);
        vector<int> adj[V];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
        }
        stack<int> st;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        vector<int> adjt[V];
        for(int i=0;i<V;i++){
            vis[i]=0;
            for(auto it:adj[i]){
                adjt[it].push_back(i);
            }
        }
        int scc=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(!vis[node]){
                scc++;
                dfs3(node,adjt,vis);
            }
        }
        return scc;
    }