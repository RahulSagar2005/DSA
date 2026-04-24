#include<bits/stdc++.h> 
using namespace std;
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
        vector<int> time(n,0);
        for(int i=0;i<n;i++){
            time[i] = ceil((double)dist[i] / speed[i]);
        }
        sort(begin(time),end(time));
        int cnt=1;
        int time_passed=1;
        for(int i=1;i<n;i++){
            if(time[i]-time_passed<=0){
                return cnt;
            }
            cnt++;
            time_passed+=1;
        }
        return cnt;
    }
};