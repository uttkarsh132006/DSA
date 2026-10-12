#include<iostream>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include <sstream>
#include<string>
using namespace std;





struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



//soln i came up with correct but not good enough
TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
    if(!root)return NULL;
      
    if(root==p||root==q){
        return root;
    }

    TreeNode* lefty=NULL;
    TreeNode* righty=NULL;

    if(root->val>p->val||root->val>q->val){
      lefty=lca(root->left,p,q);
    }
    if(root->val<p->val||root->val<q->val){
      righty=lca(root->right,p,q);
    }

    if(lefty&&righty){
      return root;
    }
    if(lefty){
      return lefty;
    }
    if(righty){
      return righty;
    }
    return NULL;

}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root,p,q);
    }
};





//optimal just start that ifnt the roots are on oposite branch return the root

TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
    if(!root)return NULL;
      
    if(root==p||root==q){
        return root;
    }

    TreeNode* lefty=NULL;
    TreeNode* righty=NULL;
    if((root->val<p->val||root->val<q->val)&&(root->val>p->val||root->val>q->val)){
      return root;
    }
    if(root->val>p->val||root->val>q->val){
      lefty=lca(root->left,p,q);
    }
    if(root->val<p->val||root->val<q->val){
      righty=lca(root->right,p,q);
    }

    if(lefty&&righty){
      return root;
    }
    if(lefty){
      return lefty;
    }
    if(righty){
      return righty;
    }
    return NULL;

}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root,p,q);
    }
};


//true optimal O(h),O(1)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
          if (p->val < root->val && q->val < root->val)//checking if both the nodes lie on the same side
            return lowestCommonAncestor(root->left, p, q);
          if (p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
          return root;//if both cond are not fullfiled then we need to reeturn the root cause now the nodes are onn opposite side 
          //and the root is the lca


          //removed the concccept of lefty and righty because only one of them gets full and others remain null
    }

