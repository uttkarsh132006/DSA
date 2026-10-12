#include<iostream>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


TreeNode* build(vector<int>& a,int& i,long long maxi){
    if(i==a.size()||a[i]>maxi)return NULL;

    TreeNode* root=new TreeNode(a[i++]);
    root->left=build(a,i,root->val);
    root->right=build(a,i,maxi);

    return root;

}

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return build(preorder,i,LONG_MAX);
    }
};