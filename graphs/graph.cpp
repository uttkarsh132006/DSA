#include<iostream>
using namespace std;

int main(){
    //graph method
    int n,m;
    int adj[n+1][m+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }

    //list 
    vector<int> adjls[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        //directed
        adjls[u].push_back(v);
        // adjls[v].push_back(u);
    }

    return 0;
}