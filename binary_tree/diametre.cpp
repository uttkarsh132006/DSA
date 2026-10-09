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
 
//hieght calculatinng fucn
int hieght(TreeNode* root){
    
    if (root==NULL)return 0;

    int lh=hieght(root->left);

    int rh=hieght(root->right);

    return 1+max(lh,rh);
}

//naive soln
//is that we go on very node and and measure the lh and rh at every node 
//and save the max and then go to every node one by one 
//at the end of it we will have the diam



int naive(TreeNode* root){
    if(root==NULL)return 0;

    int lh=hieght(root->left);
    int rh=hieght(root->right);

    int maxi=rh+lh;

    

    int left=naive(root->left);
    int right=naive(root->right);

    return max(maxi, max(left,right));

}


//optimised

int depth(TreeNode* root,int &diameter){
    if(root== NULL)return 0;

    int lh=depth(root->left,diameter);
    int rh=depth(root->right,diameter);
    diameter=max(diameter,lh+rh);
    return 1+max(lh,rh);
 }
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        depth(root,diameter);
        return diameter;
    }
};
int main(){

    




    return 0;
}