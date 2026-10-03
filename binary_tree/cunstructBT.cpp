#include<iostream>
#include<map>
#include<unordered_map>
#include<unordered_set>
using namespace std;





struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};




TreeNode* Tree(vector<int>& preorder, int preSt, int preEd,
               vector<int>& inorder, int inSt, int inEd, map<int, int>& inMap) {
    if (preSt > preEd || inSt > inEd) {
        return NULL;
    }

    TreeNode* root = new TreeNode(preorder[preSt]);

    int inRoot = inMap[root->val];
    int numsLeft = inRoot - inSt;

    root->left = Tree(preorder, preSt + 1, preSt + numsLeft, inorder, inSt,
                      inRoot - 1, inMap);
    root->right = Tree(preorder, preSt + numsLeft + 1, preEd, inorder,
                       inRoot + 1, inEd, inMap);

    return root;
}

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inMap;

        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        TreeNode* root = Tree(preorder, 0, preorder.size() - 1, inorder, 0,
                              inorder.size() - 1, inMap);

        return root;
    }
};