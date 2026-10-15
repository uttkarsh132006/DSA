#include<iostream>
using namespace std;

class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        int V=adj.size();
        vector<int>vis(V);
        vector<int>dfs;
        dfsT(0,adj,vis,dfs);
        
        return dfs;
        
    }
    
    void dfsT(int node,vector<vector<int>>& adj,vector<int>& vis,vector<int>& dfs){
        vis[node]=1;
        dfs.push_back(node);
        
        for(int it: adj[node]){
            if(!vis[it]){
                dfsT(it,adj,vis,dfs);
            }
        }
    }
};