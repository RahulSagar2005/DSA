#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        vector<int> freq;
        for(auto &it:mp){
            freq.push_back(it.second);
        }
        sort(begin(freq),end(freq));
        for(int i=0;i<freq.size();i++){
            k-=freq[i];
            if(k<0){
                return freq.size()-i;
            }
        }
        return 0;
    }
};