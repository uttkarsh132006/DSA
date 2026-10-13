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

//ubrute to pass sub tree and then if yes then pass it to a fuction which check the number of nodes 
bool check(TreeNode* root,long long low,long long high ){//THESE LOW AND HIGH IS THE RANGEE
    if(!root)return true; 

    //THIS IS THE ONLY COND OF FAIL AND REST WILL BE AUTO MATICALLT TRUE
    if(root->val>=high||root->val<=low)return false; //equL TO IS IMPORTANT QUASE QUESTION DOESNT D=STATE UNIQUE VALUES

    return check(root->left,low,root->val)&&check(root->right,root->val,high);
}

class Solution {
  public:
    int largestBst(TreeNode *root) {
         
        
    }
};



//optimal

//we have to go from bottom and the stor the largest on the left tree and the smallest on the right subtreee 
//and then compare it to the node that the largest on the left should be less then the node and the smallest
//in the node should be great then the node 


tuple<int,int,int> postorder(TreeNode* root){
    if(!root){
         return {0,INT_MIN,INT_MAX};//{size,largest in this tree,smallest in this tree}
    }

    auto [lsize,lMAX,lMIN]=postorder(root->left);
    auto [rsize,rMAX,rMIN]=postorder(root->right);

    if(root->val>lMAX&&root->val<rMIN){
        return {1+lsize+rsize,
                max(root->val,rMAX),//return the max of a root which will be either its root or the max of the right subtree
                min(root->val,lMIN)};
    }
    return {max(lsize, rsize), INT_MAX, INT_MIN};//cause now the root has not a bst and passing such value which will always be rejected 

     
}


class Solution {
  public:
    int largestBst(TreeNode *root) {
         
        return get<0>(postorder(root));//get 0 will fetch the first element of the tuple

        // tuple<int, int, int> lefty = {10, 20, 30};

        // int a = get<0>(lefty);  // 10
        // int b = get<1>(lefty);  // 20
        // int c = get<2>(lefty);  // 30
    }
};