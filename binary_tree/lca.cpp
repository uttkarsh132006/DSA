#include<iostream>
#include<map>
#include<set>
using namespace std;



//NAIVE SOLN IS THAT CREATE A VECTOR AND TRACE THE PATH OF P AND Q TO THE ROOT AND THE CHECK WHERE THE FIRST TIME BOTH PATH MEETS CONSIDERING PATHS IS WRITTEN FROM THE BOTTOM IS THE LCA
//IT IS THE BASIXC DEFINATION OF LCA 



//optimal soln



  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
TreeNode* lca(TreeNode* root,TreeNode* p, TreeNode* q){
    if(!root)return NULL;
    

    if(root==p||root==q)return root;

    TreeNode* lefty=lca(root->left,p,q);
    TreeNode* righty=lca(root->right,p,q);


    if(lefty&&righty){
        return root;
    }
    else if(lefty)
        return lefty;

    else if(righty) 
         return righty;

    else {
        return NULL;
    }

}

  class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root,p,q);
    }
};



int main(){
    return 0;
}