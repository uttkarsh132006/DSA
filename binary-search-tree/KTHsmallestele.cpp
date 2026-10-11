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

//inorder in A bst is always sorted
//doing morris order traversal
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* curr=root;
        int cnt=0;
        int ans;

        while(curr){
            if(!curr->left){
                cnt++;
                if(cnt==k){
                    ans=curr->val;
                    break;
                }
                curr=curr->right;
            }
            else {
                TreeNode* prev=curr->left;
                while(prev->right&&prev->right!=curr){
                    prev=prev->right;
                }

                if(!(prev->right)){
                    prev->right=curr;
                    curr=curr->left;
                }
                else{
                    prev->right=NULL;
                    cnt++;
                    if(cnt==k){
                        ans=curr->val;
                        break;
                    }
                    curr=curr->right;
                }
            }
        }
        return ans;


         
         

     
    }
};