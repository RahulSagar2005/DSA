#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int totalkamai=accumulate(begin(gas),end(gas),0);
        int totalkharch=accumulate(begin(cost),end(cost),0);
        if(totalkharch>totalkamai) return -1;
        int total=0;
        int r_ind=0;
        for(int i=0;i<n;i++){
            total+=gas[i]-cost[i];
            if(total<0){
                r_ind=i+1;
                total=0;
            }
        }
        return r_ind;
    }
};