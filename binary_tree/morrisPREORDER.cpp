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
    vector<int>PREORDER;
    
    while(curr!=NULL){
        if(!curr->left){
            PREORDER.push_back(curr->val);
            curr=curr->right;
        }
        else{
            TreeNode* prev=curr->left;
            while(prev->right&&prev->right!=curr){ //
                prev=prev->right;
            }

            if(prev->right == NULL){ //this is the case when the thread is not connected
                prev->right=curr;
                PREORDER.push_back(curr->val);
                curr=curr->left;
            }
            else{
                prev->right=NULL; //this is when the thread is connected
                
                curr=curr->right;
            }
        }
    }
    return PREORDER;
}