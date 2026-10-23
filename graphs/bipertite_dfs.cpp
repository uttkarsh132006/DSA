#include<iostream>
using namespace std;

//a graph is bipertite if it can be colored in 2 colors such that no adjecent color are same

//using dfs;
class Solution {
private:
    bool dfs(int node, int col, vector<vector<int>>& graph, vector<int>& color) {
        color[node] = col;

        for (int it : graph[node]) {
            if (color[it] == -1) {
                if (!dfs(it, 1 - col, graph, color))
                    return false;
            }
            else if (color[it] == col) {
                return false;               // neighbour has the same color
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1 && !dfs(i, 0, graph, color))
                return false;
        }
        return true;
    }
};