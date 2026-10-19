#include<iostream>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty())return 0;
        
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    dfs(i,j,grid,m,n,cnt);
                    
                }
            }
            
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){return -1;}
            }
        }

        return cnt;
    }
    void dfs(int row,int colm,vector<vector<int>>& grid,int m,int n,int& cnt){
        queue<pair<int,int>>q;
        q.push({row,colm});

        int dr[4]={0,0,-1,1};
        int dc[4]={-1,1,0,0};
        
        while(!q.empty()){
            int size=q.size();
            int rott=0;
            for(int i=0;i<size;i++){//to coalculate level wise
                auto [l,k]=q.front();
                q.pop();

                for(int d=0;d<4;d++){
                    int r=l+dr[d];
                    int c=k+dc[d];

                    if(0<=r&&r<m&&0<=c&&c<n){

                        if(grid[r][c]==1){
                            grid[r][c]=2;
                            rott++;
                            q.push({r,c});
                        }
                    }

                }
            }
            if(rott!=0)cnt++;//to check weather any rootten apple is rotten or only cnt++
            
        } 
        
    }
};





//correct optimal soln 
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty())return 0;

        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;
        int fresh=0;
        queue<pair<int,int>>q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});          // all rotten oranges go in first
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }

        bfs(q,grid,m,n,cnt,fresh);          // one BFS from all sources

        if(fresh!=0)return -1;              // replaces the second full-grid scan
        return cnt;
    }

    void bfs(queue<pair<int,int>>& q,vector<vector<int>>& grid,int m,int n,int& cnt,int& fresh){
        int dr[4]={0,0,-1,1};
        int dc[4]={-1,1,0,0};

        while(!q.empty()){
            int size=q.size();
            int rott=0;
            for(int i=0;i<size;i++){//to calculate level wise
                auto [l,k]=q.front();
                q.pop();

                for(int d=0;d<4;d++){
                    int r=l+dr[d];
                    int c=k+dc[d];

                    if(0<=r&&r<m&&0<=c&&c<n){

                        if(grid[r][c]==1){
                            grid[r][c]=2;
                            rott++;
                            fresh--;//to check i n the last
                            q.push({r,c});
                        }
                    }

                }
            }
            if(rott!=0)cnt++;
        }
    }
};