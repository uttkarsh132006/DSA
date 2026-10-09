#include<iostream>
using namespace std;

class TreeNode {
  public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};


TreeNode* deleteNode(TreeNode* root, int key) {
     if(root)return NULL;

     if(root->val==key){ //checking if the rootis null
        return helper(root);

     }

     TreeNode* dummy=root; //creating a dummy to return at the laast because the root wont be returning in this algorithm



    while(root){
        if(root->val>key){ //deciding where to go
            if(root->left&& root->left->val==key){ //checking the root is the key
                root->left=helper(root->left);
                break;
            }
            else{
                root=root->left;
            }
        }
        else{
            if(root->right&&root->right->val==key){
                root->right=helper(root->right);
                break;

            }
            else{
                root=root->right;
            }
        }
    }
    return dummy;
}

TreeNode* helper(TreeNode* root){ //this rearanges the bst
    if(!root->left){ //if one is null the other one is returned and is replaced with the key node in the main fuction
        return root->right;

    }
    else if(!root->right){
        return root->left;
    }

    TreeNode* rightChild=root->right;//storing ther right child of the key root
    TreeNode* leftLastRight=FindTheLastRight(root->left); //now finding the laast root of the left child if the key
    //cause it will be the largest in the left sub tree  and the left sub tree will be replaced with 
    //the orignal node
    leftLastRight->right=rightChild; //ataching the right child of the key to the right last of the left sub tree 

    return root->left; //return the root because we will be attaching the left child of the key inplace of it 


}

TreeNode* FindTheLastRight(TreeNode* root){//this will find the last right in the sub tree
    if(!root->right){
        return root;
    }
    return FindTheLastRight(root->right);
}