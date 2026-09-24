#include<iostream>
#include<stack>
#include<vector>
#include<map>
#include<unordered_set>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
      TreeNode(int val) : val(val) , left(nullptr) , right(nullptr) {}
 };


 //this is my soln not a complete one i will pass it two time to make sure every step is connected
void kin(TreeNode* root,TreeNode* target,int &k,vector<int>&ans,int &now){
    if(!root){
        now--;
        return ;
    }

    if(root==target)now=0;

    if (find(ans.begin(), ans.end(), root->val) == ans.end() && k==now) {
        ans.push_back(root->val);
    }
    
    now++;
    kin(root->left,target,k,ans,now);
    now++;
    kin(root->right,target,k,ans,now);

    
    now--;
}

//orignal
void parentMapi(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& mpp){
    if(!root)return;

    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        int siz=q.size();
        for(int i=0;i<siz;i++){
            root=q.front();
            q.pop();
            
            if(root->left){
                mpp[root->left]=root;
                q.push(root->left);
            }
            if(root->right){
                mpp[root->right]=root;
                q.push(root->right);
            }
        }
    }
}

vector<int> maini(TreeNode* root,TreeNode* target,int k,unordered_map<TreeNode*,TreeNode*>& parentMap){
    unordered_set<TreeNode*>visited;
    vector<int>ans;
    if(target){
        visited.insert(target);
    }

    int current=0;

    queue<TreeNode*>q;
    q.push(target);

    while(!q.empty()){
        int siz=q.size();
        int flag=0;
        if(current++==k){
            flag=1;
        }
        for(int i=0;i<siz;i++){
            root=q.front();
            q.pop();

            if(root->left&&visited.find(root->left)==visited.end()){
                q.push(root->left);
                if(flag){
                    ans.push_back(root->left->val);
                }
            }
            if(root->right&&visited.find(root->right)==visited.end()){
                q.push(root->right);
                if(flag){
                    ans.push_back(root->right->val);
                }
            }
            if(parentMap[root]&&visited.find(parentMap[root])==visited.end()){
                q.push(parentMap[root]);
                if(flag){
                    ans.push_back(parentMap[root]->val);
                }
            }

        }
        if(flag)break;

    }
    return ans;
}




class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parentMap;
        parentMapi(root,parentMap);
        return maini(root,target,k,parentMap);
    }
};