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



class Solution{	
	public:	
		bool uniqueBinaryTree(int a, int b){
			  return (a!=b)&&(a==2||b==2);
		}
};