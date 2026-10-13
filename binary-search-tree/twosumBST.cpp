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
//in the brute force approach we use an inorder traversal and use two pointer to get the sum 


//here we create the the pointer on from the start and other from the end 

//start pointer
class BSTfromST{
    stack<TreeNode*>st;
public:
    BSTfromST(TreeNode* root){
        pushALL(root);
    }
    int next(){
        TreeNode* temp=st.top();
        st.pop();
        pushALL(temp->right);
        return temp->val;
    }
    void pushALL(TreeNode* root){
        for(;root;st.push(root),root=root->left);
    }
};
//end pointer by reversing the above inorder traversal 
class BSTfromBK{
    stack<TreeNode*>st;
public:
    BSTfromBK(TreeNode* root){
        pushALL(root);
    }
    int next(){
        TreeNode* temp=st.top();
        st.pop();
        pushALL(temp->left);
        return temp->val;
    }
    void pushALL(TreeNode* root){
        for(;root;st.push(root),root=root->right);
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTfromST left(root); //creating two pointers 
        BSTfromBK right(root);

        int a=left.next();//smallest ele cause the iterator is using inorder traveersal
        int b=right.next();//largest ele

        while(a<b){
            if(a+b==k){
                return true;
            }
            else if(a+b>k){
                b=right.next();
            }
            else{
                a=left.next();
            }
        }
        return false;
    }
};