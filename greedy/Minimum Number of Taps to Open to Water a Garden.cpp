#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
       
        vector<int> startend(n+1,0);
        for(int i=0;i<ranges.size();i++){
            int start=max(0,i-ranges[i]);
            int end=min(n,i+ranges[i]);
            startend[start]=max(startend[start],end);
        }
        int tap=0;
        int maxend=0;
        int currend=0;
        for(int i=0;i<=n;i++){
            if(i>maxend) return -1;
            if(i>currend){
                tap++;
                currend=maxend;
            }
            maxend=max(maxend,startend[i]);
        }
        return tap;   
    }
};