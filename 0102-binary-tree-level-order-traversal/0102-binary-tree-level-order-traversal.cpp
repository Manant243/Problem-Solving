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
        que.push(NULL);
        while(!que.empty()){
            vector<int>a;
            while(que.front() != NULL){
                TreeNode* q = que.front();
                que.pop();
                a.push_back(q->val);
                if(q->left != NULL){
                    que.push(q->left);
                }
                if(q->right != NULL){
                    que.push(q->right);
                }
            }
            que.pop();
            que.push(NULL);
            ans.push_back(a);
            
            if(que.size() == 1) break;
        }
        
        return ans;
    }
};