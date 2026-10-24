#include<iostream>
using namespace std;




//with bfs algo its kahn algorithm
class Solution{
private :
    
    vector<int> indegree(vector<int> adj[],int V){
        vector<int>ind(V,0);

        //this is a syntac error cause the adjencey list is not vector<vector<int>>
        // for(const auto& it:adj){
        //     for(auto a:it){
        //         ind[a]++;
        //     }
        // }

        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {
                ind[v]++;
            }
        }

        return ind;
    }
public:
    vector<int> topoSort(int V, vector<int> adj[]){
         

        vector<int> ind=indegree(adj,V);//indegree is how many nodes are directed to it

        queue<int>q;

        for(int i=0;i<V;i++){
            if(ind[i]==0){
                q.push(i);//pushing all the node with 0 indegree there must be atleast one
            }
        }

        vector<int> topo;

        while(!q.empty()){
            int node=q.front();
            q.pop();

            topo.push_back(node);//ading the topo  with 0 degree


            for(auto it:adj[node]){
                ind[it]--;//breeaking the relation
                if(ind[it]==0)q.push(it);
            }
        }
        return topo;



    }
};
