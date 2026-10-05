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


string serialize(TreeNode* root) {
    queue<TreeNode*>q;
    if(root){
        q.push(root);
    }        
    string ans;
    while(!q.empty()){
        int siz=q.size();

        for(int i=0;i<siz;i++){
            root=q.front();
            q.pop();

            if(root){
                q.push(root->left);
            }
            if(root){
                q.push(root->right);
            }

            if(root){
                
                ans+=to_string(root->val)+",";
            }
            else{
                ans+="#,";
            }

        }
    }
    return ans;
     
    
    
}


TreeNode* deserialize(string data) {
    if(!data.empty())return NULL;

    queue<TreeNode*>q;
    stringstream ss(data);
    string token;
    getline(ss,token,','); // here inisializing the first node that is root
    TreeNode* root=new TreeNode(stoi(token));
    q.push(root);
    while (!q.empty()){
        /* code */
        TreeNode* root=q.front();
        q.pop();

        getline(ss,token,',');
        if(token=="#"){
            root->left=NULL;
        }
        else{
            TreeNode* leftNode=new TreeNode(stoi(token));
            root->left=leftNode;
            q.push(leftNode);
        }

        getline(ss,token,','); //now we did this cause once we want it for left and then right so we would have used a counter but this is better
        if(token=="#"){
            root->right=NULL;
        }
        else{
            TreeNode* rightNode=new TreeNode(stoi(token));
            root->right=rightNode;
            q.push(rightNode);
        }
    }

    return root;
    

}