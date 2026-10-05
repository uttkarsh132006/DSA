
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
    int findCeil(Node* root, int x) {
        int ciel=-1;
        while(root){
            if(x==root->data){
                return root->data;
            }
            
            if(x>root->data){
                root=root->right;
                
            }
            else{
                ciel=root->data;
                root=root->left;
            }
        }
        return ciel;
        
    }
};
