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
    
    map <TreeNode* , int> m;
    int dfs(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        
        if(m.count(root)) return m[root];
        
        int included = root->val;
        if(root->left != NULL){
            included += dfs(root->left->left) + dfs(root->left->right);
        }
        
        if(root->right != NULL){
            included += dfs(root->right->left) + dfs(root->right->right);
        }
        
        int excluded = 0;
        excluded += dfs(root->left) + dfs(root->right);
        
        return m[root] = max(included, excluded);
    }
    
    int rob(TreeNode* root) {
        return dfs(root);
    }
};