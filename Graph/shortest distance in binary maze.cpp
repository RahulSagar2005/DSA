#include<bits/stdc++.h>
using namespace std;
    int shortestPath(vector<vector<int>> &grid, pair<int, int> src,
                     pair<int, int> dst) {
        // code here
        if(src==dst) return 0;
        queue<pair<int,pair<int,int>>> q;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[src.first][src.second]=0;
        q.push({0,{src.first,src.second}});
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        while(!q.empty()){
            auto it=q.front();
            int d=it.first;
            int row=it.second.first;
            int col=it.second.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=row+dr[i];
                int nc=col+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && 1+d<dist[nr][nc]){
                    if(nr==dst.first && nc==dst.second) return d+1;
                    dist[nr][nc]=d+1;
                    q.push({d+1,{nr,nc}});
                }
            }
        }
        return -1;
    }