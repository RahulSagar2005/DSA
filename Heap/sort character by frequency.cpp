    #include<bits/stdc++.h>
    using namespace std;
    typedef pair<char,int> P;
    struct lambda{
        bool operator()(P & p1,P & p2){
            return p1.second<p2.second;// create max heap 
            // return p1.second>p2.second create a min heap 
        }
    };
    string frequencySort(string s) {
        unordered_map<char,int> mpp;
        priority_queue<P,vector<P>,lambda> pq;
        int n=s.size();
        for(int i=0;i<n;i++){
            mpp[s[i]]++;
        }
        for(auto it:mpp){
            pq.push({it.first,it.second});
        }
        string result ="";
        while(!pq.empty()){
            P temp=pq.top();
            pq.pop();
            result+=string(temp.second,temp.first);
        }
        return result;
    }