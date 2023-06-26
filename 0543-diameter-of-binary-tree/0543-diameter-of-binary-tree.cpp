/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int res = 0;
    int dfs(TreeNode* root){
        if(root == NULL) return 0;
        int left = dfs(root->left)+1;
        int right = dfs(root->right)+1;
        res = max(res, left+right-2);
        return max(left, right);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int left = dfs(root->left)+1;
        int right = dfs(root->right)+1;
        
        res = max(res, left+right-2);
        return res;
    }
};