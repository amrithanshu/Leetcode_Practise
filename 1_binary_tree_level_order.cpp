/*
 Binary Tree Level Order Traversal
Given a binary tree, return the level order traversal of its nodes' values.

Approach:
Use BFS with queue to traverse level by level.
Time Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> levelOrder(TreeNode* root){
    vector<vector<int>> res;
    if(!root) return res;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        vector<int> level;
        for(int i=0;i<n;i++){
            TreeNode* node=q.front(); q.pop();
            level.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        res.push_back(level);
    }
    return res;
}

int main(){
    TreeNode* root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);

    vector<vector<int>> res=levelOrder(root);
    for(auto &level:res){
        for(int v:level) cout<<v<<" ";
        cout<<endl;
    }
    return 0;
}
