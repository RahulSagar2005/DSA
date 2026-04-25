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
// second approach 
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        } 
        int uniquetype=mp.size();
        vector<int> freqcount(n+1,0);
        for(auto &it:mp){
            int freq=it.second;
            freqcount[freq]++;
        }
        for(int freq=1;freq<n;freq++){
            int types=min(k/freq,freqcount[freq]);
            k-=(types*freq);
            uniquetype-=types;
            if(k<=freq){
                return uniquetype;
            }
        }
        return 0;
    }
}; 
