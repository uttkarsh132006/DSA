#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

class Solution {
	public:
	int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
		
		vector<vector<int>> adj(V);
		
		for (const auto it:edges) {
			adj[it[0]].push_back(it[1]);
			adj[it[1]].push_back(it[0]);
		}
		
		vector<int>dist(V, INT_MAX);
		
		queue<pair<int, int>> q;
		q.push({src, 0});
		
		dist[src] = 0;
		
		while (!q.empty()) {
			const auto [l, k] = q.front();
			q.pop();
			
			for (auto it:adj[l]) {
				if (k + 1<dist[it]) {
					dist[it] = k + 1;
					q.push({it, k + 1});
				}
			}
		}
		
		for (int i = 0; i<V; i++) {
			if (dist[i] == INT_MAX) {
				dist[i] = -1;
			}
			else if (i == dest) {
				return dist[i];
			}
		}
		
		return dist[dest];
		
	}
};

//better soln to get the early exit

class Solution {
	public:
	int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
		
		vector<vector<int>> adj(V);
		
		for (const auto it:edges) {
			adj[it[0]].push_back(it[1]);
			adj[it[1]].push_back(it[0]);
		}
		
		vector<int>dist(V, INT_MAX);
		
		queue<pair<int, int>> q;
		q.push({src, 0});
		
		dist[src] = 0;
		
		while (!q.empty()) {
			const auto [l, k] = q.front();
			q.pop();
			if(l==dest)return dist[dest];//early exit cause in bfs smallest path will be encaountered first

			for (auto it:adj[l]) {
				if (k + 1<dist[it]) {
					dist[it] = k + 1;
					q.push({it, k + 1});
				}
			}
		}
		
		// for (int i = 0; i<V; i++) {
		// 	if (dist[i] == INT_MAX) {
		// 		dist[i] = -1;
		// 	}
		// 	else if (i == dest) {
		// 		return dist[i];
		// 	}
		// }. not required cause if we get it in upper loop we will returnn it else its unreacheable
		
		return -1; //return -1 for unreachable
		
	}
};