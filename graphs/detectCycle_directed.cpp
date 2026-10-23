#include<iostream>
#include<set>
#include<unordered_set>
using namespace std;



//optimal soln to detect cycle in directed graph using dfs
class Solution {
private:
    bool detectCycle(int src,vector<vector<int>>& adj,vector<bool>& vis,vector<bool>&pathVIS){
         vis[src]=true;
         pathVIS[src]=true;

         for(auto it : adj[src]){
            if(!vis[it]){
                bool flag=detectCycle(it,adj,vis,pathVIS);
                if(flag)return true;
            }
            else if(pathVIS[it]){
                return true;
            }
         }

         pathVIS[src]=false;

         return false;
    }
    vector<vector<int>> adj(vector<vector<int>>& pre,int numCourses){
        vector<vector<int>> ans(numCourses);
        for(auto& a:pre){
            
            ans[a[1]].push_back(a[0]);
        }
        return ans;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool>vis(numCourses,false);
        vector<bool>pathVIS(numCourses,false);//used 2 array of bool it will cost less then a single <int> array
        vector<vector<int>> adjency=adj(prerequisites,numCourses);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(detectCycle(i,adjency,vis,pathVIS)){
                    return false;
                }
            }
        }
        return true;
    }
};