#include<bits/stdc++.h> 
using namespace std;
// first approach
class Solution {
public:
    bool check(int i,int cursum, string s,int num,vector<vector<int>>&t){
        if(i==s.length()){
            return cursum==num;
        }
        if(cursum>num){
            return false;
            if(t[i][cursum]!=-1) return t[i][cursum];
        }
        bool possible=false;
        for(int j=i;j<s.length();j++){
            string sub=s.substr(i,j-i+1);
            int val=stoi(sub);
            possible=possible || check(j+1,cursum+val,s,num,t);
            if(possible==true){
                return true;
            }

        }
        return t[i][cursum]=possible;
    }
    int punishmentNumber(int n) {
        int punish=0;
        for(int num=1;num<=n;num++){
            int sq=num*num;
            string s=to_string(sq);
            vector<vector<int>> t(s.length(),vector(num+1,-1));
            if(check(0,0,s,num,t)==true){
                punish+=sq;
            }
        }
        return punish;
    }
}; 

// second approach
class Solution {
public:
    bool check(int sq,int cursum,int num){
        if(sq==0){
            return (cursum==num);
        }
        return check(sq/10,cursum+sq%10,num) || check(sq/100,cursum+sq%100,num) || check(sq/1000,cursum+sq%1000,num) ||
        check(sq/10000,cursum+sq%10000,num);
    }
    int punishmentNumber(int n) {
        int punish=0;
        for(int num=1;num<=n;num++){
            int sq=num*num;
            if(check(sq,0,num)==true){
                punish+=sq;
            }
        }
        return punish;
    }
};