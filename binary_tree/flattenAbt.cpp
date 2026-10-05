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


void preord(TreeNode* root,vector<TreeNode*>& preorder){
    if(!root)return ;

    preorder.push_back(root);
    preord(root->left,preorder);
    preord(root->right,preorder);
}

class Solution {
public:
    void flatten(TreeNode* root) {
        vector<TreeNode*>preorder;
        preord(root,preorder);
        int i=0;
        for(auto it:preorder){
            if(i==0){
                i++;
                continue;
            }

            root->left=NULL;
            root->right=it;

            root=root->right;

        }

        
    }
};