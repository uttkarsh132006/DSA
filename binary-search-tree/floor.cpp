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
    int findfloor(Node* root, int x) {
        int floor=-1;
        while(root){
            if(x==root->data){
                return root->data;
            }
            
            if(x>root->data){
                floor=root->data;
                root=root->right;
                
            }
            else{
                root=root->left;
            }
        }
        return floor;
        
    }
};
