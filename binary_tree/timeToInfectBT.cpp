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
 

void parentM(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parentMap){
    queue<TreeNode*>q;
     
    if(root)q.push(root);

    while(!q.empty()){
        root=q.front();
        q.pop();

        if(root->left){
            q.push(root->left);
            parentMap[root->left]=root;
        }

        if(root->right){
            q.push(root->right);
            parentMap[root->right]=root;
        }
    }
}

TreeNode* target(TreeNode* root, int start){
    queue<TreeNode*>q;
     
    if(root)q.push(root);

    while(!q.empty()){
        root=q.front();
        q.pop();
        if(root->val==start){
            return root;
        }
        if(root->left){
            q.push(root->left);
            
        }

        if(root->right){
            q.push(root->right);
             
        }
    }
    return NULL;
}

int time(TreeNode* root, int start,unordered_map<TreeNode*,TreeNode*>& parentMap){
    unordered_set<TreeNode*>visited;

    queue<TreeNode*>q;

     root=target(root,start);
    q.push(root);
    visited.insert(root);
    int min=0;
    while(!q.empty()){
        int siz=q.size();
        for(int i=0;i<siz;i++){
            root=q.front();
            q.pop();

            if(root->left&&visited.find(root->left)==visited.end()){
                q.push(root->left);
                visited.insert(root->left);
            }
            if(root->right&&visited.find(root->right)==visited.end()){
                q.push(root->right);
                visited.insert(root->right);
            }
            if(parentMap[root]&&visited.find(parentMap[root])==visited.end()){
                q.push(parentMap[root]);
                visited.insert(parentMap[root]);
            }

        }
        min++;
    }
    return min-1;
}


class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*>parentMap;
        parentM(root,parentMap);
        return time(root,start,parentMap);
    }
};