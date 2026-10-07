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

class Solution {
public:
    vector<int> findMinMax(TreeNode* root) {
        if(!root)return {};

        TreeNode* curr=root;
        while(curr->left)curr=curr->left;
        int mn=curr->val;

        curr=root;
        while(curr->right)curr=curr->right;
        int mx=curr->val;

        return {mn,mx};
    }
};