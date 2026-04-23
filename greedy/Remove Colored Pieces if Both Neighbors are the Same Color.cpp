#include<bits/stdc++.h> 
using namespace std;
class Solution {
public:
    bool winnerOfGame(string colors) {
        int n=colors.size();
        int a=0,b=0;
        for(int i=1;i<n-1;i++){
            if(colors[i]==colors[i-1] && colors[i]==colors[i+1]){
                if(colors[i]=='A') a++;
                else b++;
            }
        }
        return a>b;
    }
};