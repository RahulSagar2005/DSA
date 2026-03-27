#include<bits/stdc++.h>
using namespace std;
    void floydWarshall(vector<vector<int>> &dist) {
        int n = dist.size();
        const int INF = 100000000;

        // convert -1 to INF
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dist[i][j] == -1)
                    dist[i][j] = INF;
            }
        }

        // Floyd Warshall
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(dist[i][k] < INF && dist[k][j] < INF){
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        // convert INF back to -1
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dist[i][j] == INF)
                    dist[i][j] = -1;
            }
        }
    }