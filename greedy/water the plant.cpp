#include<bits/stdc++.h> 
using namespace std;
// User function Template for C++

class Solution {
  public:
    int min_sprinklers(int gallery[], int n) {
        // code here
        vector<pair<int,int>> vec;
        for(int i=0;i<n;i++){
            if(gallery[i]==-1){
                continue;
            }
            int left=max(0,i-gallery[i]);
            int right=min(n-1,i+gallery[i]);
            vec.push_back({left,right});
        }
        sort(begin(vec),end(vec));
        int target=0;
        int i=0;
        int tap=0;
        while(target<n){
            int maxrightend=0;
            while(i<vec.size()){
                if(vec[i].first<=target){
                    maxrightend=max(maxrightend,vec[i].second);
                    i++;
                }
                else{
                    break;
                }
            }
            if(target>maxrightend){
                return -1;
            }
            tap++;
            target=maxrightend+1;
        }
        return tap;
        
    }
};
