#include<bits/stdc++.h>
using namespace std;
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        vector<int> dist(n,1e9);
        dist[src]=0;
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
            dist[src]=0;
            while(!q.empty()){
                auto itr=q.front();
                int stops=itr.first;
                int node=itr.second.first;
                int dis=itr.second.second;
                q.pop();
                if(stops>k) continue;
                for(auto it:adj[node]){
                    int adjnode=it.first;
                    int edw=it.second;
                    if(edw+dis<dist[adjnode] && stops<=k){
                        dist[adjnode]=edw+dis;
                        q.push({stops+1,{adjnode,dis+edw}});
                    }
                }
            }

            if(dist[dst]==1e9) return -1;
            return dist[dst];

    }