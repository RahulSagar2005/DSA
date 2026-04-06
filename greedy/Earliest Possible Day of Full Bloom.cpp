#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n=plantTime.size();
        vector<pair<int,int>> vec(n);
        for(int i=0;i<n;i++){
            vec[i]={plantTime[i],growTime[i]};
        }
        auto lambda=[](pair<int,int> P1,pair<int,int> P2){
            return P1.second>P2.second;
        };
        sort(vec.begin(),vec.end(),lambda);
        int maxbloomdays=0;
        int prevplantdays=0;
        for(int i=0;i<n;i++){
            int currplantime=vec[i].first;
            int currgrowtime=vec[i].second;
            prevplantdays+=currplantime;
            int currplantbloomtime=prevplantdays+currgrowtime;
            maxbloomdays=max(maxbloomdays,currplantbloomtime);
        }
        return maxbloomdays;
    }
};