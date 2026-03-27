#include<bits/stdc++.h>
using namespace std;
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<
        pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        pq.push({0,{0,0}});
        int dr[4]={-1,0,1,0};int dc[4]={0,1,0,-1};
        while(!pq.empty()){
            auto it=pq.top();
            int diff=it.first;
            int row=it.second.first;
            int col=it.second.second;
            pq.pop();
            if(row==n-1 && col==m-1) return diff;
            for(int i=0;i<4;i++){
                int nr=row+dr[i];
                int nc=col+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int new_effort = max(diff, abs(heights[row][col] - heights[nr][nc]));
                    if(new_effort<dist[nr][nc]){
                        dist[nr][nc]=new_effort;
                        pq.push({new_effort,{nr,nc}});
                    }
                }
            }
        }
        return 0;
    }