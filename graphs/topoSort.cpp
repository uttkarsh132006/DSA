#include<iostream>
using namespace std;


//for ug (undirected graph);


//it only exist in dag(directed acyclic graph) is there exist a edge between u and v u apprears before v



class Solution {
private:
    void dfs(int src,vector<vector<int>>& adj,vector<bool>& vis,stack<int>& st){
        
        vis[src]=true;
        for(auto it:adj[src]){
            if(!vis[it]){
                dfs(it,adj,vis,st);
            }
            
        }
        st.push(src);//at end to push it when every dfs go good
        
    } 
    vector<vector<int>> adjecency(int V,vector<vector<int>>& edges){
        vector<vector<int>>ans(V);
        
        for(const auto& a:edges){
            ans[a[0]].push_back(a[1]);//oposite dirn then usual
        }
        return ans;
    }
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
         vector<bool> vis(V,false);
         vector<int>ans(V,0);
         vector<vector<int>> adj=adjecency(V,edges);
         stack<int>st;
         
         for(int i=0;i<V;i++){
             if(!vis[i]){
                 dfs(i,adj,vis,st);
             }
         }
         int cnt=0;
         while(!st.empty()){
             int a=st.top();
             st.pop();
             ans[cnt++]=a;
             
         }
         return ans;
         
    }
};