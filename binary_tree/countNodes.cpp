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


//this is my soln 

//but not knowing it it was 0(n) as the miss travers the whole array in the worst case

 bool isLeaf(TreeNode* root){
    return (root)&&(!root->left)&&(!root->right);
}


void hieght(TreeNode* root,int& h){
    
    if(!root)return;
    h++;
    if(!isLeaf(root->left))hieght(root->left,h);
}

int miss(TreeNode* root,int& misi,int& h,int curr){
    if(!root){
        misi++;
        return 0;
    }

    if(isLeaf(root)&&curr==h)return -1;

    int righti=miss(root->right,misi,h,curr+1);
    if(righti==-1)return -1;
    int lefti=miss(root->left,misi,h,curr+1);
    if(lefti==-1)return -1;

    if(righti||lefti)return -1;

    else {
        return 0;
    }

}

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int h=0;
        int nodes=0;
        hieght(root,h);
        nodes+=(pow(2,h)-1);
        int misi=0;
        
        miss(root,misi,h,0);
        nodes+=(pow(2,h)-misi);
         
        return nodes;

        


    }
};


int lh(TreeNode* root){
    if(!root){
        
        return 0;
    }
    int leftH=lh(root->left);
    leftH++;
    return leftH;

}
int rh(TreeNode* root){
    if(!root){
        return 0;
    }
    int rightH=rh(root->right);
    rightH++;
    return rightH;
}

 

 

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root)return 0;

        
        int leftHieght=lh(root);
        int rightHieght=rh(root);

        if(leftHieght==rightHieght)return pow(2,leftHieght)-1;

        return 1+ countNodes(root->left)+countNodes(root->right); // see as we know there will be a complete tree 
        
        
        


    }
};






