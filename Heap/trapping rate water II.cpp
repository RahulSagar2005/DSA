#include<bits/stdc++.h>
using namespace std;
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
        int trapRainWater(vector<vector<int>>& heightMap) {
        int m=heightMap.size();
        int n=heightMap[0].size();
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        // left most column and right column(0,n-1)
        for(int row=0;row<m;row++){
            pq.push({heightMap[row][0],{row,0}});
            pq.push({heightMap[row][n-1],{row,n-1}});
            vis[row][0]=true;
            vis[row][n-1]=true;
        }
        // top most row and bottom most row(0,m-1);
        for(int col=0;col<n;col++){
            pq.push({heightMap[0][col],{0,col}});
            pq.push({heightMap[m-1][col],{m-1,col}});
            vis[0][col]=true;
            vis[m-1][col]=true;
        }
        int water=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int ht=it.first;
            int i=it.second.first;
            int j=it.second.second;
            for(int d=0;d<4;d++){    
                int ni=i+dr[d];
                int nj=j+dc[d];
                if(ni>=0 && ni<m && nj>=0 && nj<n && !vis[ni][nj]){
                    water+=max(ht-heightMap[ni][nj],0);
                    pq.push({max(ht,heightMap[ni][nj]),{ni,nj}});
                    vis[ni][nj]=true;
                }
            }
        }
        return water;
    } 