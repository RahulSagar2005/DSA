#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n=costs.size();
        sort(costs.begin(),costs.end());
        int cnt=0;
        for(int i=0;i<n;i++){
            if(coins>=costs[i]){
                coins-=costs[i];
                cnt++;
            }
            else{
                break;
            }
        }
        return cnt;
        
    }
};