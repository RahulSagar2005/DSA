#include<bits/stdc++.h>
using namespace std;
void dfs(int sr,int sc,int inicolor,vector<vector<int>>& image,vector<vector<int>>& ans,int drow[],
    int dcol[],int newcolor){
        ans[sr][sc]=newcolor;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int nrow=sr+drow[i];
            int ncol=sc+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==inicolor && 
            ans[nrow][ncol]!=newcolor){
                dfs(nrow,ncol,inicolor,image,ans,drow,dcol,newcolor);
            }
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans=image;
        int inicolor=ans[sr][sc];
        if(inicolor==color) return image;
        int drow[4]={-1,0,1,0};
        int dcol[4]={0,1,0,-1};
        dfs(sr,sc,inicolor,image,ans,drow,dcol,color);
        return ans;
    }