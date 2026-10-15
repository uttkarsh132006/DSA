#include<iostream>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V=isConnected.size();
        vector<int>vis(V+1);
        int cnt=0;
        for(int i=1;i<=V;i++){
            if(vis[i]==0){
                cnt++;
                dfs(i,isConnected,vis);
            }
        }
        return cnt;

    }
    void dfs(int node,vector<vector<int>>& mat,vector<int>& vis){
        vis[node]=1;
        for(int i=0;i<mat.size();i++){
            if(mat[node-1][i]==1&&!vis[i+1]){//node -1 cause node is been taken out from the visited list which is 1 based and stores the corrct name bu the matrix is 0 based and vis i+1 cuase i is 0 based 
                dfs(i+1,mat,vis);
            }
        }
    }

};