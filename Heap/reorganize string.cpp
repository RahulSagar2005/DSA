#include<bits/stdc++.h>
using namespace std;
// using max heap
string reorganizeString(string s) {
        vector<int> count(26,0);
        int n=s.size();
        for(int i=0;i<n;i++){
            count[s[i]-'a']++;
            if(count[s[i]-'a']>(n+1)/2) return "";
        }
        priority_queue<pair<int,char>> pq;
        for(int i=0;i<26;i++){
            char ch=i+'a';
            if(count[i]>0){
                pq.push({count[i],ch});
            }
        }
        string res="";
        while(pq.size()>=2){
            auto it1=pq.top();
            pq.pop();
            int freq1=it1.first;
            char ch1=it1.second;
            auto it2=pq.top();
            pq.pop();
            int freq2=it2.first;
            char ch2=it2.second;
            res.push_back(ch1); freq1--;
            res.push_back(ch2);freq2--;
            if(freq1>0) pq.push({freq1,ch1});
            if(freq2>0) pq.push({freq2,ch2});
        }
        if(!pq.empty()){
            res.push_back(pq.top().second);
        }
        return res; 
    }
// greedy approach 
string reorganizeString(string s) {
        vector<int> count(26,0);
        int n=s.size();
        int maxfreq=0;
        char charmaxfreq;
        for(int i=0;i<n;i++){
            count[s[i]-'a']++;
            if(count[s[i]-'a']>maxfreq){
                maxfreq=count[s[i]-'a'];
                charmaxfreq=s[i];
            }
            if(count[s[i]-'a']>(n+1)/2) return "";
        }
        string res=s;
        int it=0;
        while(count[charmaxfreq-'a']>0){
            res[it]=charmaxfreq;
            it+=2;
            count[charmaxfreq-'a']--;
        }
        for(int i=0;i<26;i++){
            char ch=i+'a';
            while(count[ch-'a']>0){
                if(it>=n){
                    it=1;
                }
                res[it]=ch;
                it+=2;
                count[ch-'a']--;
            }
        }
        return res;
    }