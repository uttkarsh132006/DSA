#include<iostream>
using namespace std;

class Solution {
    public:
    vector < int > shortestPath(int N, int M, vector < vector < int >> & edges) {
        vector<vector<pair<int,int>>> adj(N);
        vector<int>inord(N,0);

         
        for(const auto& it:edges){
            adj[it[0]].push_back({it[1],it[2]});//ADJECENCY CONSTRUCTION
            inord[it[1]]++;//inorder construction for topo sort 
        }

        //now topo sort
        queue<int>q;
        for(int i=0;i<N;i++){
            if(!inord[i]){
                q.push(i);
            }
        }        
        //this is a dag so we do not need to check the cycles 

        vector<int>topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);

            for(const auto& it:adj[node]){
                if(--inord[it.first]==0)q.push(it.first);
            }


        }
        int src=0;
        vector<int> dist(N,INT_MAX);
        dist[src]=0;
        //now we are using top sort because that the nodes thaat can be reached from the src wiill be only 
        //right of that node and every one will be marked -1;
        for(auto u:topo){
            if(dist[u]==INT_MAX)continue;

            for(const auto& it:adj[u]){
                int v=it.first,w=it.second;
                if(dist[u]+w<dist[v]){
                    dist[v]=dist[u]+w;
                }
            }
        }
        //unreacheable is intialised with -1
        for(int i=0;i<N;i++){
            if(dist[i]==INT_MAX)dist[i]=-1;
        }

        return dist;
        
    }
};