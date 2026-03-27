#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
   
    public:
     vector<int> rank,parent,size;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
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
    bool isvalid(int nr,int nc,int n){
        return (nr>=0 && nc>=0 && nr<n && nc<n);
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                    int dr[]={-1,0,1,0};
                    int dc[]={0,1,0,-1};
                    for(int it=0;it<4;it++){
                        int nr=i+dr[it];
                        int nc=j+dc[it];
                        if(isvalid(nr,nc,n) && grid[nr][nc]==1){
                            int nodeno=i*n+j;
                            int adjnodeno=nr*n+nc;
                            ds.unionBySize(nodeno,adjnodeno);
                        }
                    }
            }
        }
        int mx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) continue;
                int dr[]={-1,0,1,0};
                int dc[]={0,1,0,-1};
                set<int> comp;
                for(int it=0;it<4;it++){
                    int nr=i+dr[it];
                    int nc=j+dc[it];
                    if(isvalid(nr,nc,n)){
                        if(grid[nr][nc]==1){
                            comp.insert(ds.findUPar(nr*n+nc));
                        }
                    }
                }
                int ts=0;
                for(auto it:comp){
                    ts=ts+ds.size[it];
                }
                mx=max(mx,ts+1);
            }
        }
        for(int i=0;i<n*n;i++){
            mx=max(mx,ds.size[ds.findUPar(i)]);
        }
        return mx;
    }