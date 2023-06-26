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
    bool ans = true;
    int dfs(TreeNode* root){
        if(root == NULL) return 0;
        if(!ans) return 0;
        
        int left = dfs(root->left)+1;
        int right = dfs(root->right)+1;
        
        if(abs(left-right) > 1){
            ans = false; 
        }
        return max(left, right);
    }
    
    bool isBalanced(TreeNode* root) {
        int a = dfs(root);
        return ans;
    }
};