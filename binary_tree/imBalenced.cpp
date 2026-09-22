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


 //balenced binary tree

    int checkHieght(TreeNode* root){
        if (root==NULL)return 0;

        int lh=checkHieght(root->left);

        if(lh==-1)return -1;

        int rh=checkHieght(root->right);
        if(rh==-1)return -1;

        //after this gets -1 it will breakthrough to the top to return -1
        if(abs(lh-rh)>1)return -1;

        return 1+max(lh,rh);
    }

     bool isBalanced(TreeNode* root) {
        return checkHieght(root)!=-1;
    
    }

int main(){
    return 0;
}