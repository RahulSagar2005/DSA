#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int brokenCalc(int sv, int t) { 
        if(sv>=t){
            return (sv-t);
        }
        if(t%2==0){
            return 1+brokenCalc(sv,t/2);
        }
        return 1+brokenCalc(sv,t+1);
    }
};