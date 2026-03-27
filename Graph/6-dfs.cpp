#include<bits/stdc++.h>
using namespace std;
  void dfs(int node,vector<vector<int>> &adj,int vis[],vector<int> &ls){
      vis[node]=1;
      ls.push_back(node);
      for(auto it:adj[node]){
          if(!vis[it]){
              dfs(it,adj,vis,ls);
          }
      }
  }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n=adj.size();
        int vis[n]={0};
        vector<int> ls;
        int start=0;
        dfs(start,adj,vis,ls);
        return ls;
    }
