#include<iostream>
using namespace std;


//terminal node-node which outdegree is 0
//safe node -every path from that node leads to terminal node

//every one who is the part of the cyle cannot be a safe node 

//and every on who is directed to any of the elements of thaat cycle also cannot be the safe node


//else every one can be a safe node



//by detecting cycle method
class Solution {
private:
    bool detectCycle(int src, vector<vector<int>>& adj, vector<bool>& vis,
                     vector<bool>& pathVIS, vector<bool>& safeNode) {
        vis[src] = true;
        pathVIS[src] = true;

        for (auto it : adj[src]) {
            if (!vis[it]) {
                bool flag = detectCycle(it, adj, vis, pathVIS, safeNode);
                if (flag)
                    return true; // here early return means the SAFENODE IS
                                 // STILL FALSE WHICH COVERS THE CASE OF CYCLE
                                 // AND THE NODE CONNECTED
                // THINK AGAIN YOU WILL GET THIS
            } else if (pathVIS[it]) {
                return true;
            }
        }

        pathVIS[src] = false;
        safeNode[src] = true;
        return false; // ignore these fasl and true
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(n, false);
        vector<bool> pathVIS(n, false);
        vector<bool> safeNode(n, false);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                detectCycle(i, graph, vis, pathVIS, safeNode);
            }
        }
        vector<int> nodes;
        for (int i = 0; i < n; i++) {
            if (safeNode[i]) {
                nodes.push_back(i);
            }
        }
        return nodes;
    }
};