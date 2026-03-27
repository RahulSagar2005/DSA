#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
  vector<string> result;
  void solve(int i,int j,vector<vector<int>>& m,int n,string &path){
      if(i<0 || i>=n || j<0 || j>=n || m[i][j]==0) return ;
      if(i==n-1 && j==n-1){
        result.push_back(path);
        return;
    } 
      m[i][j]=0;
      path.push_back('D');
      solve(i+1,j,m,n,path);
      path.pop_back();
      path.push_back('L');
      solve(i,j-1,m,n,path);
      path.pop_back();
      path.push_back('R');
      solve(i,j+1,m,n,path);
      path.pop_back();
      path.push_back('U');
      solve(i-1,j,m,n,path);
      path.pop_back();
      m[i][j]=1;
  }
    vector<string> ratInMaze(vector<vector<int>>& m) {
        string path="";
        if(m[0][0] ==0) return{};
        int n=m.size();
        solve(0,0,m,n,path);
        return result;
    }
};