#include<iostream>
using namespace std;



//if you can divide a graph in 2 colurs alternatively and it satisfies whole 
//is a bipertite graph

//so every linier graph is a bipertite
//and graph with even leght of cycle is a bipertite as well
//and graph with odd is not
class Solution {
private:
    bool bipartite(int src,vector<vector<int>>& graph, vector<int>& color) {
        queue<int> q;
        q.push(src);
        color[src]=0;
         
        while (!q.empty()) {

            int size = q.size();
            for (int i = 0; i < size; i++) {
                int node = q.front();
                q.pop();
                 

                for (auto it : graph[node]) {
                    if (color[it] == -1) {
                        q.push(it);
                        color[it] = color[node] ? 0 : 1;
                    } else {
                        if (color[it] == color[node]) { // when its nieghbour
                                                        // has the same color
                            return false;
                        }
                    }
                }
            }
             
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (bipartite(i,graph, color) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};