#include<iostream>
using namespace std;
#include<vector>
#include<stack>
    //recursive method

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};  

    //recursive method
    void postorder(TreeNode* root,vector<int>&arr){
        
        if(root==NULL)return;

        postorder(root->left,arr);
        postorder(root->right,arr);
        arr.push_back(root->val);
    }
//stack method mu method
// reversed the ans vector and used pre order algo entered left first the right
    vector<int>postorderst(TreeNode* root){
        vector<int>ans;

        stack<TreeNode*>st;

        st.push(root);
        while(!st.empty()){
            root=st.top();
            st.pop();

            if(root->left!=NULL)st.push(root->left);

            if(root->right!=NULL)st.push(root->left);

            ans.push_back(root->val);
        }
        reverse(ans.begin(),ans.end());

        return ans;
    }

    //double stack method
    vector<int> postorderTraversal(TreeNode* root) {
       
        stack<TreeNode*>st;
        stack<TreeNode*>ans;
        if(root==NULL)return {};
        st.push(root);
        while(!st.empty()){
            root=st.top();

            st.pop();

            ans.push(root);

            //you have to keep the seq same here because to two stack it will be corrected

            if(root->left!=NULL)st.push(root->left);

            if(root->right!=NULL)st.push(root->right);


            
        }
        vector<int>s;
        while(!ans.empty()){
            s.push_back(ans.top()->val);
            ans.pop();
        }
        return s;
    }
int main(){

    




    return 0;
}