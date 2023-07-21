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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue <TreeNode*> que;
        
        if(!root) return ans;
        
        que.push(root);
        bool dir = true;
        while(!que.empty()){
            int size = que.size();
            vector <int> cur(size);
            
            for(int i = 0; i < size; i++){
                TreeNode* node = que.front();
                que.pop();
                
                int index = dir ? i : size-i-1;
                
                cur[index] = node->val;
                if(node->left){
                    que.push(node->left);
                }
                if(node->right){
                    que.push(node->right);
                }
            }
            
            dir = !dir;
            ans.push_back(cur);
        }
        
        return ans;
    }
};