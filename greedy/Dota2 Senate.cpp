#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void removesenate(string &senate,int idx,char ch,vector<bool> &removed,int n){
        while(true){
            if(senate[idx]==ch && removed[idx]==false){
                removed[idx]=true;
                break;
            }
            idx=(idx+1)%n;
        }
    }
    string predictPartyVictory(string senate) { 
        int n=senate.size();
        int R_count=count(begin(senate),end(senate),'R');
        int D_count=n-R_count;
        int idx=0;
        vector<bool> removed(n,false);
        while(R_count>0 && D_count>0){
            if(removed[idx]==false){
                if(senate[idx]=='R'){
                    removesenate(senate,(idx+1)%n,'D',removed,n);
                    D_count--;
                }
                else{
                    removesenate(senate,(idx+1)%n,'R',removed,n);
                    R_count--;
                }
            }
            idx=(idx+1)%n;
        }
        return R_count==0?"Dire":"Radiant";
        
    }
};