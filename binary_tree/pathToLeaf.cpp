#include<iostream>
#include<map>
#include<set>
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


//this si what i came up with not nowing that the pass by value will make this soln bigO of n^2 
//the pass b y value will copy every value every time thats waht became an naive sioln

// bool isLeaf(Node* root){
//     return (root)&&(!root->left)&&(!root->right);
// }

// void pat(Node* root,vector<vector<int>>& ans,vector<int>&path){
//     if(!root)return;
//     path.push_back(root->data);
    
//     if(!isLeaf(root->left)){
//         pat(root->left,ans,path);
//     }
//     else {
//         path.push_back(root->left->data);
//         ans.push_back(path);
//         path.pop_back();
//     }
    
//     if(!isLeaf(root->right)){
//         pat(root->right,ans,path);
//     }
//     else{
//         path.push_back(root->right->data);
//         ans.push_back(path);
//         path.pop_back();
//     }
// }

// class Solution {
//   public:
//     vector<vector<int>> paths(Node* root) {
//         vector<vector<int>>ans;
//         vector<int>path;
//         if(isLeaf(root))return {{root->data}};
//         pat(root,ans,path);
        
//         return ans;
//     }
// };



 

bool isLeaf(Node* root){
    return (root)&&(!root->left)&&(!root->right);
}



void leaf(Node* root,vector<vector<int>>&ans,vector<int>&path){
    if(!root)return;
    
    path.push_back(root->data);
    
    if(isLeaf(root)){
        ans.push_back(path);
        path.pop_back();
        return;
    }
    else {
        leaf(root->left,ans,path);
        leaf(root->right,ans,path);
        
    }
    path.pop_back();
}

class Solution {
  public:
    vector<vector<int>> paths(Node* root) {
       vector<vector<int>>ans;
       
       vector<int>path;
       leaf(root,ans,path);
       return ans;
        
    }
};









 