#include<iostream>
using namespace std;

class TreeNode {
  public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};


class BSTIterator{
    stack<TreeNode*>st;//declaring a stck to do iterative inorder traversal
public:
    BSTIterator(TreeNode* root){
        pushALL(root);
    }
    bool hasNext(){
        return !st.empty();
    }
    int next(){
        TreeNode* temp=st.top();
        st.pop();
        pushALL(temp->right);
        return temp->val;
    }
    void pushALL(TreeNode* root){//work to push allmt he elements in the stack data structure
        while(root){
            st.push(root);
            root=root->left;        
        }
    }

};