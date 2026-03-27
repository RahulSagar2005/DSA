# include<bits/stdc++.h>
using namespace std;
    void dfs(int row,int col,vector<vector<int>> &vis,vector<pair<int,int>> &vec,vector<vector<int>>& grid,int n,int m,int dr[],int dc[],int row0,int col0){
       vis[row][col]=1;
       vec.push_back({row-row0,col-col0});
       for(int i=0;i<4;i++){
           int nr=row+dr[i];
           int nc=col+dc[i];
           if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]==1){
               dfs(nr,nc,vis,vec,grid,n,m,dr,dc,row0,col0);
           }
       }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        vector<vector<int>> vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>> st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    vector<pair<int,int>> vec;
                    dfs(i,j,vis,vec,grid,n,m,dr,dc,i,j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }