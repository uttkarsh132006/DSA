#include<iostream>
#include<set>
#include<unordered_set>
using namespace std;



class Solution{
private:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,-1,0,1};
    void dfs(int row,int colm,vector<pair<int,int>>& coord,vector<vector<int>>& grid,vector<vector<int>>& vis,
        int row0,int colm0,int m,int n){
            vis[row][colm]=1;
            coord.push_back({row-row0,colm-colm0});

            for(int d=0;d<4;d++){
                int r=row+dr[d];
                int c=colm+dc[d];

                if(0<=r&&r<m&&0<=c&&c<n){
                    if(grid[r][c]==1&&!vis[r][c]){
                        dfs(r,c,coord,grid,vis,row0,colm0,m,n);
                    }
                }
            }

    }
public:
    int countDistinctIsland(vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));

        set<vector<pair<int,int>>>st;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1&&!vis[i][j]){
                    vector<pair<int,int>>coord;
                    dfs(i,j,coord,grid,vis,i,j,m,n);
                    st.insert({coord});
                }
            }
        }

        return st.size();
    }
};


//yes this is ggod but if we try unordered set in place of set to match 0(1) rather 0(#island) it would give error cause 
//unordeered set cant have vector<pair<int,int>> as value 

class Solution {
private:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, -1, 0, 1};

    void dfs(int row, int colm, vector<pair<int,int>>& coord,
             vector<vector<int>>& grid, vector<vector<int>>& vis,
             int row0, int colm0, int m, int n) {
        vis[row][colm] = 1;
        coord.push_back({row - row0, colm - colm0});

        for (int d = 0; d < 4; d++) {
            int r = row + dr[d];
            int c = colm + dc[d];
            if (0 <= r && r < m && 0 <= c && c < n &&
                grid[r][c] == 1 && !vis[r][c]) {
                dfs(r, c, coord, grid, vis, row0, colm0, m, n);
            }
        }
    }

public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        unordered_set<string> st;                    // changed

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    vector<pair<int,int>> coord;
                    dfs(i, j, coord, grid, vis, i, j, m, n);

                    string key;                      // new: vector -> string
                    for (auto& [a, b] : coord) {
                        key += to_string(a) + "," + to_string(b) + ";";
                    }
                    st.insert(key);
                }
            }
        }
        return st.size();
    }
};