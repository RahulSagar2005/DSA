#include<bits/stdc++.h>
using namespace std;
    class DisjointSet{
    vector<int> rank,parent,size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findUPar(int node){
        if(node==parent[node]) return node;
        return parent[node]=findUPar(parent[node]);
    }
    void unionByRank(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }   
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxr=0;
        int maxc=0;
        for(auto it:stones){
            maxr=max(maxr,it[0]);
            maxc=max(maxc,it[1]);
        }
        DisjointSet ds(maxr+maxc+1);
        unordered_map<int,int> stonenode;
        for(auto it:stones){
            int noderow=it[0];
            int nodecol=it[1]+maxr+1;
            ds.unionBySize(noderow,nodecol);
            stonenode[noderow]=1;
            stonenode[nodecol]=1;
        }
        int cnt=0;
        for(auto it:stonenode){
            if(ds.findUPar(it.first)==it.first){
                cnt++;
            }
        }
        return n-cnt;
    }