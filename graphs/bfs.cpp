#include<iostream>
using namespace std;

class Solution {
  public:
     
    
    vector<int> bfsOfGraph(int V, vector<vector<int>> edges) {//V is number of nodes
      vector<int>bfs;  
      vector<int>vis(V);
      queue<int>q;
      vis[0]=1;

      q.push(0);
      while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it : edges[node]){
          if(!vis[it]){
            vis[it]=1;
            q.push(it);

          }
        }
      }
      return bfs;

    }
};
