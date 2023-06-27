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
    int cnt = -1;
    void dfs(TreeNode* root, int height, vector<int> &ans){
        if(height > cnt){
            ans.push_back(root->val);
            cnt++;
        }
        if(root->right != NULL){
            dfs(root->right, height+1, ans);
        }
        if(root->left != NULL){
            dfs(root->left, height+1, ans);
        }
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector <int> ans;
        if(!root) return ans;
        
        dfs(root, 0, ans);
        return ans;
    }
};