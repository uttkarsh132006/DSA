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

//this is what i thought pretty bulshit

bool isLeaf(TreeNode* root){
    return (root)&&(!root->left&&!root->right)&&(root);
}

int bst(TreeNode* root){
    if(isLeaf(root)){
        return root->val;
    }

    if(!root->left&&(root->right->val)>(root->val)){
        return root->right->val;
    }
    if(!root->right&&(root->left->val)<(root->val)){
        return root->val;
    }

    int lft=bst(root->left);
    if(lft==-1)return -1;
    int rgt=bst(root->right);
    if(rgt==-1)return -1;

    if(lft<root->val&&root->val<rgt){
        return root->right->val;
    }
    else {
        return -1;
    }

}

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root)return true;

        int reti=bst(root);
        int maxi=INT_MIN;
        TreeNode* curr=root;
        while(curr->right){
            curr=curr->right;
        }
        maxi=curr->val;
        if(reti==maxi){
            return true;
        }
        else{
            return false;
        }


    }
};


bool check(TreeNode* root,long long low,long long high ){//THESE LOW AND HIGH IS THE RANGEE
    if(!root)return true; 

    //THIS IS THE ONLY COND OF FAIL AND REST WILL BE AUTO MATICALLT TRUE
    if(root->val>=high||root->val<=low)return false; //equL TO IS IMPORTANT QUASE QUESTION DOESNT D=STATE UNIQUE VALUES

    return check(root->left,low,root->val)&&check(root->right,root->val,high);
}

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return check(root,LONG_MIN,LONG_MAX);


    }
};