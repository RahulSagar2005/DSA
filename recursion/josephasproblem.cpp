#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> arr;
        for(int i=1;i<=n;i++){
            arr.push_back(i);
        }
        int i=0;
        while(arr.size()>1){
            int ind=(i+k-1)%arr.size();
            arr.erase(arr.begin()+ind);
            i=ind;
        }
        return arr[0];
    }
}; 
//using queue
class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i=1;i<=n;i++){
            q.push(i);
        }
        while(q.size()>1){
            for(int c=1;c<=k-1;c++){
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }
        return q.front();
    }
};
// recursion
class Solution {
public:
    int solve(int n,int k){
        if(n==1){
            return 0;
        }
        int idx=solve(n-1,k);
        idx=(idx+k)%n;
        return idx;
    }
    int findTheWinner(int n, int k) {
        int res=solve(n,k);
        return res+1;
    }
};