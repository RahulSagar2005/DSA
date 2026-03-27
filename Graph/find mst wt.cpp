#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
        vector<int> rank,parent,size;

    public:

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
int kruskalsMST(int V, vector<vector<int>> &edges) {

    vector<pair<int,pair<int,int>>> edge;

    for(auto it:edges){

        int u=it[0];
        int v=it[1];
        int wt=it[2];

        edge.push_back({wt,{u,v}});
    }

    sort(edge.begin(),edge.end());

    DisjointSet ds(V);

    int mstwt=0;

    for(auto it:edge){

        int wt=it.first;
        int u=it.second.first;
        int v=it.second.second;

        if(ds.findUPar(u)!=ds.findUPar(v)){
            mstwt+=wt;
            ds.unionBySize(u,v);
        }
    }

    return mstwt;
}