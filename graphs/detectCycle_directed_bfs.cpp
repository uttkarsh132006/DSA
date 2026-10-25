#include<iostream>
#include<set>
#include<unordered_set>
using namespace std;



//kahn algo to find cycle using bfs
class Solution {
private:
    // Helper: build adjacency list (edge b -> a) and fill indegree
    vector<vector<int>> adj(vector<vector<int>>& pre, int numCourses,
                            vector<int>& indegree) {
        vector<vector<int>> ans(numCourses);
        for (auto& a : pre) {
            ans[a[1]].push_back(a[0]);
            indegree[a[0]]++;              // a has one more prerequisite
        }
        return ans;
    }

    // Helper: returns true if a cycle exists
    bool detectCycle(int numCourses, vector<vector<int>>& adj,
                     vector<int>& indegree) {
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
            if (indegree[i] == 0) q.push(i);

        int processed = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            processed++;

            for (int it : adj[node]) {
                if (--indegree[it] == 0)
                    q.push(it);
            }
        }
        return processed != numCourses;    // leftover nodes => cycle
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adjency = adj(prerequisites, numCourses, indegree);

        return !detectCycle(numCourses, adjency, indegree);
    }
};