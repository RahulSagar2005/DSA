#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(int curnum,int n,vector<int>&res){
        if(curnum>n){
            return;
        }
        res.push_back(curnum);
        for(int i=0;i<=9;i++){
            int newnum=(curnum*10)+i;
            if(newnum>n){
                return;
            }
            solve(newnum,n,res);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for(int i=1;i<=9;i++){
        solve(i,n,res);
        }
        return res;
    }
};