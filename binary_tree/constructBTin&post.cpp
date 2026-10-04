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




TreeNode* TreeROOT(vector<int>& postorder, int postSt, int postEd,
               vector<int>& inorder, int inSt, int inEd, map<int, int>& inMap) {

    if (postSt > postEd || inSt > inEd) {
        return NULL;
    }

    TreeNode* root = new TreeNode(postorder[postSt]);

    int inROOT = inMap[root->val];
    int numsRight = inEd - inROOT;

    root->right = TreeROOT(postorder, postSt + 1, postSt + numsRight, inorder,
                       inROOT + 1, inEd, inMap);
    root->left = TreeROOT(postorder, postSt + numsRight + 1, postEd, inorder, inSt,
                      inROOT - 1, inMap);

    return root;
}

class Solution {
public:
    TreeNode* buildTree(vector<int>& postorder, vector<int>& inorder) {
        map<int, int> inMap;

        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        vector<int> revi=postorder;
        reverse(revi.begin(), revi.end());
        TreeNode* root = TreeROOT(revi, 0, postorder.size() - 1, inorder, 0,
                              inorder.size() - 1, inMap);

        return root;
    }
};