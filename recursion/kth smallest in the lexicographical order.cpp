#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countk(long curr,long next,int n){
        int cnno=0;
        while(curr<=n){
            cnno+=(next-curr);
            curr*=10;
            next*=10;
            next=min(next,long(n+1));
        }
        return cnno;
    }
    int findKthNumber(int n, int k) {
        int curr=1;
     k-=1;
        while(k>0){
            int cnt=countk(curr,curr+1,n);
            if(cnt<=k){
                curr++;
                k-=cnt;
            }
            else{
                curr*=10;
                k-=1;
            }
        }
        return curr;
    }
};