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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* curr = root;
        TreeNode* res = new TreeNode(val);
        
        if(!root) return res;
        
        while(true){
            if(val > curr->val){
                if(curr->right){
                    curr = curr->right;
                }
                else{
                    curr->right = res;
                    break;
                }
            }
            else{
                if(curr->left){
                    curr = curr->left;
                }
                else{
                    curr->left = res;
                    break;
                }
            }
            
        }
        return root;
    }
};