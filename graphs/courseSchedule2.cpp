#include<iostream>
#include<set>
#include<unordered_set>
using namespace std;

//this is my appraoch
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
    vector<vector<int>> adjen(int numCourses, vector<vector<int>>& prerequisites){
        vector<vector<int>> ans(numCourses);

        for(const auto& it:prerequisites){
            ans[it[1]].push_back(it[0]);
        }

        return ans;
    }

    void dfs(int src,vector<vector<int>>& adj,vector<bool>& vis,stack<int>& st){
        vis[src]=true;

        for(auto it :adj[src]){
            if(!vis[it]){
                dfs(it,adj,vis,st);
            }
        }

        st.push(src);
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool>vis(numCourses,false);
        vector<bool> vis2(numCourses,false);
        vector<bool> pathVis(numCourses,false);
        vector<vector<int>>adj=adjen(numCourses,prerequisites);

        for(int i=0;i<numCourses;i++){
            if(!vis2[i]&&detectCycle(i,adj,vis2,pathVis)){
                return {};
            }
        }

        stack<int>st;
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }

        vector<int>ans(numCourses);
        int cnt=0;
        while(!st.empty()){
            ans[cnt++]=st.top();
            st.pop();
        }

        return ans;
        
    }
};

//now instead of using two traversal its best to use single with kahn algorihtm
//kahn algo to get topo and detect cycle as well

class Solution {
private:

    vector<vector<int>> adjen(int numCourses, vector<vector<int>>& prerequisites){
        vector<vector<int>> ans(numCourses);

        for(const auto& it:prerequisites){
            ans[it[1]].push_back(it[0]);
        }

        return ans;
    }

    vector<int> topo(int numCourses,vector<vector<int>>& adj,vector<int>& ind){
        queue<int>q;
        vector<int>ans;

        for(int i=0;i<numCourses;i++){
            if(ind[i]==0)q.push(i);
        }

        int processed=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            processed++;

            for(auto it:adj[node]){
                if(--ind[it]==0)q.push(it);
            }
        }

        if(processed==numCourses)return ans;

        else{
            return {};
        }
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ind(numCourses,0);
        vector<vector<int>> adj=adjen(numCourses,prerequisites);

        for(const auto& it:adj){
            for(auto a:it){
                ind[a]++;
            }
        }

        return topo(numCourses,adj,ind);
    }
};

//more cleaner version where i do only single loop to get the adj list and the indegree

class Solution {
private:

    vector<vector<int>> adjen(int numCourses, vector<vector<int>>& prerequisites, vector<int>& ind){
        vector<vector<int>> ans(numCourses);

        for(const auto& it:prerequisites){
            ans[it[1]].push_back(it[0]);
            ind[it[0]]++;
        }

        return ans;
    }

    vector<int> topo(int numCourses,vector<vector<int>>& adj,vector<int>& ind){
        queue<int>q;
        vector<int>ans;

        for(int i=0;i<numCourses;i++){
            if(ind[i]==0)q.push(i);
        }

        int processed=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            processed++;

            for(auto it:adj[node]){
                if(--ind[it]==0)q.push(it);
            }
        }

        if(processed==numCourses)return ans;

        else{
            return {};
        }
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ind(numCourses,0);
        vector<vector<int>> adj=adjen(numCourses,prerequisites,ind);

        return topo(numCourses,adj,ind);
    }
};



//0ms soln

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses, 0);

        for(int i=0; i<prerequisites.size(); i++) {
            indegree[prerequisites[i][0]]++;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }    

        queue<int> q;
        for(int i=0; i<numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topoSort;
        vector<int> empty;

        while(!q.empty()) {
            int curr = q.front();
            q.pop();

            topoSort.push_back(curr);

            for(int node: adj[curr]) {
                indegree[node]--;
                if(indegree[node] == 0) {
                    q.push(node);
                }
             }
        }

        return topoSort.size() == numCourses ? topoSort : empty;
    }
};