#include<iostream>
using namespace std;



//brute force soln wriiten by me soln is correct 
//but gives tle i large cases cause passing of vis by non refrence 

//and passing it with refrence will make it wrong
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();

        vector<vector<int>>vis(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    bfs(mat,vis,i,j);
                }
            }
        }
        return mat;
    }

    void bfs(vector<vector<int>>& mat,vector<vector<int>> vis,int row,int colm){
        int m=mat.size();
        int n=mat[0].size();
        queue<pair<int,int>>q;

        q.push({row,colm});

        vis[row][colm]=1;

        int dr[4]={0,0,-1,1};
        int dc[4]={-1,1,0,0};
        int cnt=0;

        while(!q.empty()){
            int size=q.size();
            
            for(int i=0;i<size;i++){
                auto [l,k]=q.front();
                q.pop();

                if(mat[l][k]==0){
                    goto exitLoop;
                }
                
                for(int d=0;d<4;d++){
                    int r=l+dr[d];
                    int c=k+dc[d];

                    if(0<=r&&r<m&&0<=c&&c<n){

                        if(vis[r][c]==0){
                            q.push({r,c});
                            vis[r][c]=1;
                        }
                         
                    }
                }
            }
            cnt++;
        }
        exitLoop: 

        mat[row][colm]=cnt;
    }
};





//optimal
 
class Solution {
    const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // Helper: is (r, c) inside the grid?
    bool inBounds(int r, int c, int rows, int cols) {
        return r >= 0 && r < rows && c >= 0 && c < cols;
    }

    // Helper: seed the queue with all zeros, mark 1s as unvisited (-1)
    void initQueue(vector<vector<int>>& mat,
                   vector<vector<int>>& dist,
                   queue<pair<int, int>>& q) {
        int rows = mat.size(), cols = mat[0].size();
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (mat[r][c] == 0) {
                    dist[r][c] = 0;
                    q.push({r, c});
                }
            }
        }
    }

    // Helper: process one cell, relax its unvisited neighbours
    void expand(int r, int c, int rows, int cols,
                vector<vector<int>>& dist,
                queue<pair<int, int>>& q) {
        for (auto& d : dirs) {
            int nr = r + d[0], nc = c + d[1];
            if (inBounds(nr, nc, rows, cols) && dist[nr][nc] == -1) {
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols, -1));
        queue<pair<int, int>> q;

        initQueue(mat, dist, q);

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            expand(r, c, rows, cols, dist, q);
        }
        return dist;
    }
};
