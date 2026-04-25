#include<bits/sdtc++.h>
using namespace std;
class Solution {
public:
    int n;
    vector<vector<int>>t;
    int solve(int idx,vector<int>& heights,int bricks,int ladders){
        if(idx==n-1){
            return 0;
        }
        if(t[bricks][ladders]!=-1){
            return t[bricks][ladders];
        }
        if(heights[idx+1]<heights[idx]){
            return t[bricks][ladders]=1+solve(idx+1,heights,bricks,ladders);
        }
        else{
            int bybr=0;
            int bylad=0;
            int diff=heights[idx+1]-heights[idx];
            if(bricks>diff){
                bybr=1+solve(idx+1,heights,bricks-diff,ladders);
            }
            if(ladders>0){
                bylad=1+solve(idx+1,heights,bricks,ladders-1);
            }
            return t[bricks][ladders]=max(bybr,bylad);
        }
        return -1;
    }
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        n=heights.size();
        t=vector<vector<int>>(bricks+1,vector<int>(ladders+1,-1));
        return solve(0,heights,bricks,ladders);
        
    }
};

// lazy greedy approach 
class Solution {
public:

    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n=heights.size();
        priority_queue<int> pq;
        int i=0;
        for(;i<n-1;i++){
            if(heights[i+1]<heights[i]){
                continue;
            }
            int diff=heights[i+1]-heights[i];
            if(bricks>=diff){
                bricks-=diff;
                pq.push(diff);
            }
            else if(ladders>0){
                if(!pq.empty()){
                    int max_brick=pq.top();
                    if(max_brick>diff){
                        bricks+=max_brick;
                        pq.pop();
                        bricks-=diff;
                        pq.push(diff);
                    }
                }
                ladders--;
                
            }
            else{
                break;
            }
        }
        return i;
        
    }
};