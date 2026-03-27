#include<bits/stdc++.h>
using namespace std;
    void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>> &board,int n,int m,int dr[],int dc[]){
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            int nr=row+dr[i];
            int nc=col+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0 && board[nr][nc]=='O'){
                vis[nr][nc]=1;
                dfs(nr,nc,vis,board,n,m,dr,dc);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            if(!vis[0][j] && board[0][j]=='O'){
                dfs(0,j,vis,board,n,m,dr,dc);
            }
            if(!vis[n-1][j] && board[n-1][j]=='O')
            {
                dfs(n-1,j,vis,board,n,m,dr,dc);
            }
        }
          for(int i=0;i<n;i++){
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(i,0,vis,board,n,m,dr,dc);
            }
            if(!vis[i][m-1] && board[i][m-1]=='O')
            {
                dfs(i,m-1,vis,board,n,m,dr,dc);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }