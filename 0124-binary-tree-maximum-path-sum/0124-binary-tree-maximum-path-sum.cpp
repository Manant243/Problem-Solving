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
    int ans = 0, maxi = -1e6;
    int calc(TreeNode* root){
        if(!root) return 0;
        maxi = max(maxi, root->val);
        int left = max(calc(root->left), 0);
        int right = max(calc(root->right), 0);
        ans = max(ans, left+right+root->val);
        return max(left, right)+root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        maxi = max(maxi, root->val);
        int sum = max(calc(root->left), 0) + max(calc(root->right), 0) + root->val;
        ans = max(ans, sum);
        
        if(ans == 0) return maxi;
        return ans;
    }
};