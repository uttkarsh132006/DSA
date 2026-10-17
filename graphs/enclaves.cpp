#include<iostream>
using namespace std;



//this is written by me the problem here is that it returns early without traversing leaving nodes with 1 behind 
//so when the main loop in the mai fuction come to that 1 it goes again and maybe this time 
// its a enclave
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;
        int nodes=0;
        for(int i=1 ; i<m-1;i++){
            for(int j=1;j<n-1;j++){
                cnt=0;
                if(grid[i][j]==1 && encl(grid,i,j,cnt) ){
                    nodes+=cnt;
                }
            }
        }
        return nodes;
    }


    bool encl(vector<vector<int>>& grid,int row,int colm,int& cnt){
        queue<pair<int,int>>q;

        int m=grid.size();
        int n=grid[0].size();
        

        q.push({row,colm});
        grid[row][colm]=0;
        cnt++;
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,1,-1};

        while(!q.empty()){
            auto [l,k]=q.front();
            q.pop();

            for(int d=0;d<4;d++){
                int r=l+dr[d];
                int c=k+dc[d];

                if((0<=r&&r<m)&&(0<=c&&c<n)){
                    
                    if(grid[r][c]==1){
                        q.push({r,c});
                        grid[r][c]=0;
                        cnt++;
                    }
                }
                else{
                    return false;
                }
            }


        }
        return true;



    }
};


//optimal
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        int nodes = 0;
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                cnt = 0;
                if (grid[i][j] == 1 && encl(grid, i, j, cnt)) {
                    nodes += cnt;
                }
            }
        }
        return nodes;
    }

    bool encl(vector<vector<int>>& grid, int row, int colm, int& cnt) {
        queue<pair<int, int>> q;

        int m = grid.size();
        int n = grid[0].size();

        q.push({row, colm});
        grid[row][colm] = 0;
        cnt++;
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, 1, -1};
        bool ok = true;
        while (!q.empty()) {
            auto [l, k] = q.front();
            q.pop();

            for (int d = 0; d < 4; d++) {
                int r = l + dr[d];
                int c = k + dc[d];

                if ((0 <= r && r < m) && (0 <= c && c < n)) {

                    if (grid[r][c] == 1) {
                        q.push({r, c});
                        grid[r][c] = 0;
                        cnt++;
                    }
                } else {
                    ok = false;
                }
            }
        }
         return ok;
    }
};


//optimL AND BEST 

// move on the boundry and sink every connected land and then move on innere land and mark the 

class Solution {
public:

    void dfs(int i, int j, vector<vector<int>>&grid){//function to sink every land 
        int m= grid.size(), n= grid[0].size();
        if (i<0 || j<0 || i>=m || j>=n || grid[i][j]==0){return;}
        grid[i][j]=0;
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m= grid.size(), n= grid[0].size();
        for (int i=0; i<m; i++){
            dfs(i,0,grid); 
            dfs(i,n-1,grid);
        }
        for (int i=0; i<n; i++){
            dfs(0,i,grid); 
            dfs(m-1,i,grid);
        }
        int ans=0;
        for (int i=1; i<m-1; i++){
            for (int j=1; j<n-1; j++){
                if (grid[i][j]==1){
                    ans+=1;
                }
            }
        }
        return ans;
    }
};