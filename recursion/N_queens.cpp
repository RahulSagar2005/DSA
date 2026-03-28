#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<vector<string>> res;
    bool isvalid(vector<string> & board,int row,int col,int n){
        // look upward
        for(int i=n-1;i>=0;i--){
            if(board[i][col]=='Q')
            return false;
        }
        // look left diagonal
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }
    void solve(vector<string> & board,int row,int n){
        if(row>=n){
            res.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
            if(isvalid(board,row,i,n)){
            board[row][i]='Q';
            solve(board,row+1,n);
            board[row][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        solve(board,0,n);
        return res;
    }
};
// 2nd approach
class Solution {
public:
vector<vector<string>> res;
    unordered_set<int> cols;
        unordered_set<int> diag;
        unordered_set<int> adiag;
    void solve(vector<string> & board,int row,int n){
        if(row>=n){
            res.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
            int diagc=row+i;
            int adiagc=row-i;
            if(cols.find(i)!=cols.end() || diag.find(diagc)!=diag.end() || adiag.find(adiagc)!=adiag.end()){
                continue;
            }
            cols.insert(i);
            diag.insert(diagc);
            adiag.insert(adiagc);
            board[row][i]='Q';
            solve(board,row+1,n);
            cols.erase(i);
            diag.erase(diagc);
            adiag.erase(adiagc);
            board[row][i]='.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        
        solve(board,0,n);
        return res;
    }
};