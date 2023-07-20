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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue <TreeNode*> que;
        
        if(!root) return ans;
        
        que.push(root);
        while(!que.empty()){
            int b = que.size();
            vector <int> curr;
            while(b--){
                TreeNode* a = que.front();
                que.pop();
                if(a->left){
                    que.push(a->left);
                }
                if(a->right){
                    que.push(a->right);
                }
                curr.push_back(a->val);
            }
            ans.push_back(curr);
        }
        
        return ans;
    }
};