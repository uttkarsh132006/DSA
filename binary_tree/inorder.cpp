#include<iostream>
using namespace std;
#include<vector>
#include<stack>
    //recursive method

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};  

    //recursive method
    void inorder(TreeNode* root,vector<int>&arr){
        
        if(root==NULL)return;

        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
//stack method
    vector<int>inorderst(TreeNode* root){
             vector<int>ans;
             stack<TreeNode*>st;

             
             while(true){
                if(root!=NULL){
                    st.push(root);
                    root=root->left;
                }
                else{
                    if(st.empty()==true)break;
                    root=st.top();
                    st.pop();
                    ans.push_back(root->val);
                    root=root->right;
                }
             }
             return ans;
    }

int main(){

    




    return 0;
}