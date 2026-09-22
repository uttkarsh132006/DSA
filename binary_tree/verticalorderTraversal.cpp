#include<iostream>
#include<map>
#include<set>
using namespace std;





   
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

  
//son that i thought of for the each node is map but it didn,t work we have to use 
//a map<pair<int,int>,multiset<int>>mpp;
//cause of identical nodes
void inorder1(TreeNode* root, int rows, int colm, map<pair<int,int>, multiset<int>>& mpp){
    if(!root) return;
    inorder1(root->left, rows+1, colm-1, mpp);
    mpp[{colm, rows}].insert(root->val);//this is how you enter in a map with a multiset if it wasnt for the multi set ihte insett would have been replaced with = root->VAL
    inorder1(root->right, rows+1, colm+1, mpp);
}

vector<vector<int>> verticalTraversal(TreeNode* root){
    map<pair<int,int>, multiset<int>> mpp;
    inorder1(root, 0, 0, mpp);

    vector<vector<int>> ans;
    int currCol = INT_MIN;

    for(auto& [key, vals] : mpp){//& is because we do not want to make the copys of keys and vals just to throw it 
        int colm = key.first;
        if(colm != currCol){
            ans.push_back({});      // start a new column group
            currCol = colm;
        }
        for(int v : vals){
            ans.back().push_back(v);
        }
    }

    return ans;
}






//optimised soln involing vector tuples then a sort

void inorder(TreeNode* root, int rows, int colm, vector<tuple<int,int,int>>& mpp ){
    if(!root) return;
    inorder(root->left, rows+1, colm-1, mpp);
    mpp.push_back({colm,rows,root->val});
    inorder(root->right, rows+1, colm+1, mpp);
}

 
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int rows,colm=0;
        vector<tuple<int,int,int>>mpp;

        inorder(root,0,0,mpp);
        sort(mpp.begin(),mpp.end());
         int currCol=INT_MIN;

        vector<vector<int>>ans;

        for(auto& [colm,row,vals]:mpp){
            if(currCol!=colm){
                ans.push_back({});
                currCol=colm;
            }
             
            ans.back().push_back(vals);

             
        }
        return ans;

    }
 