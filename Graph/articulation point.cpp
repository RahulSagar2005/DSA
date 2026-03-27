#include<bits/stdc++.h>
using namespace std;
    int timer=1;
    void dfs(int node,int parent,vector<int>&vis,vector<int> adj[],
    int low[], int tin[],vector<int> &mark){
        vis[node]=1;
        low[node]=tin[node]=timer;
        timer++;
        int child=0;
        for(auto it:adj[node]){
            if(it==parent) continue;
            if(!vis[it]){
                dfs(it,node,vis,adj,low,tin,mark);
                low[node]=min(low[node],low[it]);
                if(low[it]>=tin[node] && parent!=-1){
                    mark[node]=1;
                }
                child++;
            }
            else{
                low[node]=min(low[node],tin[it]);
            }
        }
        if(child>1 && parent==-1){
            mark[node]=1;
        }
    }
    vector<int> articulationPoints(int n, vector<int> adj[]) {
        // Code here
        vector<int> vis(n,0);
        int tin[n];
        int low[n];
        vector<int> mark(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,-1,vis,adj,low,tin,mark);
            }
        }
        vector<int> ans;
        for(int i=0;i<mark.size();i++){
            if(mark[i]==1){
                ans.push_back(i);
            }
        }
        if(ans.size()==0) return {-1};
        else return ans;
        
    }