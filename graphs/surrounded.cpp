#include<iostream>
using namespace std;

//optimal soln written by me

class Solution {
public:
    int dr[4]={0,0,-1,1};
    int dc[4]={-1,1,0,0};
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();

        vector<vector<int>>vis(m,vector<int>(n,0));

        queue<pair<int,int>>q;

        for(int i=0;i<m;i++){
            if(board[i][0]=='O'&&vis[i][0]==0){
                q.push({i,0});
                vis[i][0]=1;
                bfs(q,vis,board);
            }

            if(board[i][n-1]=='O'&&vis[i][n-1]==0){
                q.push({i,n-1});
                vis[i][n-1]=1;
                bfs(q,vis,board);
            }
        }

        for(int j=1;j<n-1;j++){
            if(board[0][j]=='O'&&vis[0][j]==0){
                q.push({0,j});
                vis[0][j]=1;
                bfs(q,vis,board);
            }

            if(board[m-1][j]=='O'&&vis[m-1][j]==0){
                q.push({m-1,j});
                vis[m-1][j]=1;
                bfs(q,vis,board);
            }
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(board[i][j]=='O'&&vis[i][j]==0){
                    board[i][j]='X';
                    
                }
            }
        }



    }

    void bfs(queue<pair<int,int>>&q,vector<vector<int>>& vis,vector<vector<char>>& board){
        int m=board.size();
        int n=board[0].size();

        while(!q.empty()){
            auto [l,k]=q.front();
            q.pop();

            for(int d=0;d<4;d++){
                int r=l+dr[d];
                int c=k+dc[d];

                if(0<=r && r<m && 0<=c && c<n){

                    if(board[r][c]=='O'&&vis[r][c]==0){
                        q.push({r,c});
                        vis[r][c]=1;
                    }
                }
            }
        }
    }

    


};


//cleaner without vis array

class Solution {
    static constexpr int dr[4] = {0, 0, -1, 1};
    static constexpr int dc[4] = {-1, 1, 0, 0};

    void bfs(queue<pair<int,int>>& q, vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && board[nr][nc] == 'O') {
                    board[nr][nc] = '#';      // mark safe in place
                    q.push({nr, nc});
                }
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        queue<pair<int,int>> q;

        // seed all border 'O's
        for (int i = 0; i < m; i++) {
            for (int j : {0, n - 1}) {
                if (board[i][j] == 'O') { board[i][j] = '#'; q.push({i, j}); }
            }
        }
        for (int j = 1; j < n - 1; j++) {
            for (int i : {0, m - 1}) {
                if (board[i][j] == 'O') { board[i][j] = '#'; q.push({i, j}); }
            }
        }

        bfs(q, board);

        // final pass: captured -> X, safe -> O
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                board[i][j] = (board[i][j] == '#') ? 'O' : (board[i][j] == 'O' ? 'X' : board[i][j]);
    }
};