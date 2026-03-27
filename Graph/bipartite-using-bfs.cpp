#include<bits/stdc++.h>
using namespace std;
bool check(int start,vector<vector<int>> &edges, vector<int> & color){
      color[start]=0;
      queue<int> q;
      q.push(start);
      while(!q.empty()){
          int node=q.front();
          q.pop();
          for(auto it:edges[node]){
              if(color[it]==-1){
                  color[it]=!color[node];
                  q.push(it);
              }
              else if(color[it]==color[node]) return false;
          }
      }
      return true;
  }
    bool isBipartite(int V, vector<vector<int>> &edges) {
        vector<int> color(V,-1);
        vector<vector<int>> adj(V);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
}
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(check(i,adj,color)==false) return false;
            }
        }
        return true;
    }