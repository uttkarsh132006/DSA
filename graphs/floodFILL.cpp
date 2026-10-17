#include<iostream>
using namespace std;





//this is what i wrote it works only if color!=image[sr][sc] if its equal to then its infinite loop cause i do not use any visited array ind checks again for the same niegbour and never stops checking
//optmal without edge case
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        fill(image,sr,sc,color);
        return image;
    }

    void fill (vector<vector<int>>& image, int sr, int sc, int color){
        int m=image.size();
        int n=image[0].size();
        queue<pair<int,int>>q;

        q.push({sr,sc});
        int css=image[sr][sc];
        image[sr][sc]=color;
        int dr[4]={0,0,-1,1};
        int dc[4]={-1,1,0,0};

        while(!q.empty()){
            auto[l,k]=q.front();
            q.pop();

            for(int d=0;d<4;d++){
                int r=l+dr[d];
                int c=k+dc[d];

                if((0<=r&&r<m)&&(0<=c&&c<n)){

                    if(image[r][c]==css){
                        image[r][c]=color;
                        q.push({r,c});
                    }
                }
            }


        }
    }
};

//optimal son
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(color==image[sr][sc])return image;//edge caase
        
        
        int css=image[sr][sc];
        fill(image,sr,sc,color,css);
        return image;
    }

    void fill (vector<vector<int>>& image, int sr, int sc, int color,int css){
        int m=image.size();
        int n=image[0].size();
        queue<pair<int,int>>q;

        q.push({sr,sc});
         
        image[sr][sc]=color;
        int dr[4]={0,0,-1,1};
        int dc[4]={-1,1,0,0};

        while(!q.empty()){
            auto[l,k]=q.front();
            q.pop();

            for(int d=0;d<4;d++){
                int r=l+dr[d];
                int c=k+dc[d];

                if((0<=r&&r<m)&&(0<=c&&c<n)){

                    if(image[r][c]==css){
                        image[r][c]=color;
                        q.push({r,c});
                    }
                }
            }


        }
    }
};
