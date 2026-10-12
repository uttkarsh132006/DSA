#include<iostream>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
 

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* succ=NULL;
        Node* pre=NULL;
        Node* curr=root;
        vector<Node*>ans(2);
        while(root){
            if(root->data>=key){
                root=root->left;
            }
            else{
                // if(!pre)pre=root;
                // if(pre->data<root->data)pre=root; //we need not to check just simply 
                pre=root;
                root=root->right;
            }
        }
        ans[0]=pre;
        
        while(curr){
            if(curr->data<=key){
                curr=curr->right;
            }
            else{
                // if(!succ)succ=curr;
                // if(succ->data>curr->data)succ=curr;//smae here
                succ=root;
                curr=curr->left;
            }
        }
        ans[1]=succ;
        
        return ans;
        
    }
};