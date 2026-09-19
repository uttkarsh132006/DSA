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
    void preorder(TreeNode* root,vector<int>&arr){
        
        if(root==NULL)return;

        arr.push_back(root->val);
        preorder(root->left,arr);
        preorder(root->right,arr);
    }
//stack method
    vector<int>preorderst(TreeNode* root){
            vector<int>ans;
             
            if(root==NULL)return ans;

            stack<TreeNode*>st;

            st.push(root);
            while(!st.empty()){
                root=st.top();
                st.pop();
                if(root->right!=NULL)st.push(root->right);

                if(root->left!=NULL)st.push(root->left);

                ans.push_back(root->val);

            }
            return ans;
    }

int main(){

    




    return 0;
}