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

//ques says onlly two nuumbers are swapepd 
//morris traversal
//self wriiten
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* prev = NULL;
        TreeNode* first = NULL;
        TreeNode* last = NULL;
        TreeNode* curr = root;
        while (curr) {
            if (!curr->left) {
                if (prev && !first && prev->val > curr->val) {//case when prev is not null and first is null we need to modify both
                    first = prev;
                    last = curr;
                } else if (prev && prev->val > curr->val) {//case when first is not null we need to only modify last
                    last = curr;
                }
                prev = curr;//we do it after check cause we want to store prev calude told us 
                curr = curr->right;
            } else {
                TreeNode* preq = curr->left;
                while (preq->right && preq->right != curr) {
                    preq = preq->right;
                }
                if (!preq->right) {
                    preq->right = curr;
                    curr = curr->left;
                } else {
                    preq->right = NULL;
                    if (prev && !first && prev->val > curr->val) {
                        first = prev;
                        last = curr;
                    } else if (prev && prev->val > curr->val) {
                        last = curr;
                    }
                    prev = curr;
                    curr = curr->right;
                }
            }
        }

        swap(first->val, last->val);
    }
};