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
    TreeNode* prev = NULL;
    void func(TreeNode* curr){
        if(curr == NULL) return;
        if(curr->right){
            func(curr->right);
        }
        if(curr->left){
            func(curr->left);
        }
        curr->right = prev;
        curr->left = NULL;
        prev = curr;
    }
    
    void flatten(TreeNode* root) {
        func(root);    
    }
};