#include<iostream>
using namespace std;

class Solution {
    
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'&&vis[i][j]==0){
                    bfs(grid,vis,i,j,m,n);
                    cnt++;
                }
            }
        }
        return cnt;
        

        
    }
    void bfs(vector<vector<char>>& grid,vector<vector<int>>& vis,int i,int j,int m,int n){
         queue<pair<int,int>>q;
         q.push({i,j});

         vis[i][j]=1;
        int dr[4]={0,0,-1,1};//creating all the 4 niegbour and thier corespoing indx
        int dc[4]={1,-1,0,0};
         while(!q.empty()){
            auto [l,k]=q.front();
            q.pop();

            for(int d=0;d<4;d++){
                int r=l+dr[d];
                int c=k+dc[d];

                if((0<=r&&r<m)&&(0<=c&&c<n)){//checking all the four nieghbour are in the bounds

                    if(grid[r][c]=='1'&&!vis[r][c]){//checking if the array is one and not visited 
                        vis[r][c]=1;
                        q.push({r,c});
                    }
                }
            }
         }
    }
};

//one more soln in which not taking the visited array

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    bfs(grid,i,j,m,n);
                    cnt++;
                }
            }
        }
        return cnt;
    }

    void bfs(vector<vector<char>>& grid,int i,int j,int m,int n){
        queue<pair<int,int>>q;
        q.push({i,j});

        grid[i][j]='0';                    // replaces vis[i][j]=1
        int dr[4]={0,0,-1,1};
        int dc[4]={1,-1,0,0};
        while(!q.empty()){
            auto [l,k]=q.front();
            q.pop();

            for(int d=0;d<4;d++){
                int r=l+dr[d];
                int c=k+dc[d];

                if((0<=r&&r<m)&&(0<=c&&c<n)){

                    if(grid[r][c]=='1'){   // no vis check needed
                        grid[r][c]='0';    // replaces vis[r][c]=1
                        q.push({r,c});
                    }
                }
            }
        }
    }
};