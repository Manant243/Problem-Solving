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
    
    void invert(TreeNode* root){
        if(root == NULL) return;
        swap(root->left, root->right);
        if(root->left != NULL){
            invert(root->left);
        }
        if(root->right != NULL){
            invert(root->right);
        }
    }
    
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
};