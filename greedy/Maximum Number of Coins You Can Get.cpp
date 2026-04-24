#include<bits/stdc++.h> 
using namespace std;
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n=piles.size();
        sort(begin(piles),end(piles));
        int a=n-1;
        int m=n-2;
        int b=0;
        int res=0;
        while(m>b){
            res+=piles[m];
            b++;
            a-=2;
            m-=2;
        }
        return res;
    }
};

// second approach 
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n=piles.size();
        int res=0;
        sort(begin(piles),end(piles));
        for(int m=n/3;m<n;m+=2){
            res+=piles[m];
        }
        return res;
    }
};