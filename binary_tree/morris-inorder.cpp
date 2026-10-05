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



vector<int> morrisINORDER(TreeNode* root){
    TreeNode* curr=root;
    vector<int>INORDER;
    
    while(curr!=NULL){
        if(!curr->left){
            INORDER.push_back(curr->val);
            curr=curr->right;
        }
        else{
            TreeNode* prev=curr->left;
            while(prev->right&&prev->right!=curr){ //
                prev=prev->right;
            }

            if(prev->right == NULL){ //this is the case when the thread is not connected
                prev->right=curr;
                curr=curr->left;
            }
            else{
                prev->right=NULL; //this is when the thread is connected
                INORDER.push_back(curr->val);
                curr=curr->right;
            }
        }
    }
    return INORDER;
}