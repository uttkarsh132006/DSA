#include<iostream>
#include<stack>
#include<vector>
using namespace std;

struct TreeNode {
     int data;
     TreeNode *left;
     TreeNode *right;
      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 };

//boundry of a bt

bool isLeaf(TreeNode* root){
    return (!root->left&&!root->right);

}
//take care of all the null ptr and leaf nodes

void leftBoundry(TreeNode* root,vector<int>&ans){
    if(root->left)root=root->left;

    else return;
    while(!isLeaf(root)){
        ans.push_back(root->data);
        if(root->left){
             root=root->left;
        }
        else {
            root=root->right;
        }
    }
}
void leaf(TreeNode* root,vector<int>&ans){
    if(!root)return;

    leaf(root->left,ans);

    if(isLeaf(root))ans.push_back(root->data);

    leaf(root->right,ans);

}
void rightBoundry(TreeNode*root,vector<int>&ans){
    if(root->right)root=root->right;
    else return;

    stack<int>st;
    while(!isLeaf(root)){
        
        st.push(root->data);
        
        if(root->right){
            root=root->right;
        }
        else {
            root=root->left;
        }

    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
}
class Solution{
public:
    vector <int> boundary(TreeNode* root){
        vector<int>ans;
        if(!root)return {};

        ans.push_back(root->data);
        if(isLeaf(root)) return ans ;

        //first calling the left side

        leftBoundry(root,ans);
        //then calling the leaf nodes
        leaf(root,ans);
        //the the right boundry
        rightBoundry(root,ans);

        return ans;

    }
};



int main(){
    return 0;
}