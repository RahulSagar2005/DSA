#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        int left=firstPlayer;
        int right= secondPlayer;
        if(left==n-right+1){
            return {1,1};
        }
        if(left>n-right+1){
            int temp=n-left+1;
            left=n-right+1;
            right=temp;
        }
        int minr=n;
        int maxr=1;
        int nextroundplayer=(n+1)/2;
        if(right<=nextroundplayer){// case 1 both on the same side
        int countleft=left-1;
        int midcount=right-left-1;
        for(int i=0;i<=countleft;i++){// i-> survivorleft j-> survivormid
            for(int j=0;j<=midcount;j++){
                int p1=i+1;
                int p2=p1+j+1;
                vector<int> temp=earliestAndLatest(nextroundplayer,p1,p2);
                minr=min(minr,temp[0]+1);
                maxr=max(maxr,temp[1]+1);
            }
        }
        }
        else{// both on opposite end
            int fightright=n-right+1;
            int countleft=left-1;
            int midcount=fightright-left-1;
            int remainmidcount=right-fightright-1;
            for(int i=0;i<=countleft;i++){// i-> survivorleft j-> survivormid
            for(int j=0;j<=midcount;j++){
                int p1=i+1;
                int p2=p1+j+(remainmidcount+1)/2+1;
                vector<int> temp=earliestAndLatest(nextroundplayer,p1,p2);
                minr=min(minr,temp[0]+1);
                maxr=max(maxr,temp[1]+1);
            }
        }
        }
        return {minr,maxr};

    }
};