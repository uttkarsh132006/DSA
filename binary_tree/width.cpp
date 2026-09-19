 
#include<iostream>
#include<map>
#include<set>
using namespace std;
 
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

  //width of a tree

  int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> st;

        if (root)
            st.push({root, 0});
        unsigned long maxi = 0;
        while (!st.empty()) {
            int size = st.size();
            unsigned long lev = 0, first = 0, last = 0;
            unsigned long level_start = st.front().second;
            for (int i = 0; i < size; i++) {
                auto it = st.front();
                st.pop();

                if (i == 0) {
                    first = it.second;
                }
                if (it.first->left)
                    st.push(
                        {it.first->left, 2 * (it.second - level_start) + 1});
                if (it.first->right)
                    st.push(
                        {it.first->right, 2 * (it.second - level_start) + 2});

                if (i == size - 1)
                    last = it.second;
            }
            lev = (last - first) + 1;
            maxi = max(lev, maxi);
        }
        return maxi;
    }
 