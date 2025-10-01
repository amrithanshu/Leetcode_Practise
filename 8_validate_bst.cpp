/*
 Validate Binary Search Tree
Given a binary tree, determine if it is a valid BST.

Approach:
DFS with min-max range validation.
Time Complexity: O(n)
*/

#include <iostream>
#include <limits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

bool validate(TreeNode* root, long minVal, long maxVal){
    if(!root) return true;
    if(root->val<=minVal || root->val>=maxVal) return false;
    return validate(root->left, minVal, root->val) && validate(root->right, root->val, maxVal);
}

bool isValidBST(TreeNode* root){
    return validate(root, LONG_MIN, LONG_MAX);
}

int main(){
    TreeNode* root=new TreeNode(2);
    root->left=new TreeNode(1);
    root->right=new TreeNode(3);
    cout << (isValidBST(root) ? "True" : "False") << endl;
    return 0;
}
