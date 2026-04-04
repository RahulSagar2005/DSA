#include<bits/stdc++.h> 
using namespace std;
class Solution {
public:
    char kthCharacter(long long k, vector<int>& op) {
        if(k==1) return 'a';
        int n=op.size();
        long long len=1;
        long long optype=-1;
        long long index=-1;
        for(int i=0;i<n;i++){
            len*=2;
            if(len>=k){
                optype=op[i];
                index=k-len/2;
                break;
            }
        }
        char ch=kthCharacter(index,op);
        if(optype==0){
            return ch;
        }
        return ch=='z'?'a':ch+1;
    }
};