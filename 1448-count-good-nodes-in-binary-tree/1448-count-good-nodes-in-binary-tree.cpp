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
    int cnt = 1;
    void dfs(TreeNode* root, int maxx){
        if(root->val >= maxx){
            maxx = root->val; cnt++;
        }
        if(root->right != NULL){
            dfs(root->right, maxx);
        }
        if(root->left != NULL){
            dfs(root->left, maxx);
        }
    }
    
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        if(root->right != NULL){
            dfs(root->right, root->val);
        }
        if(root->left != NULL){
            dfs(root->left, root->val);
        }
        return cnt;
    }
};