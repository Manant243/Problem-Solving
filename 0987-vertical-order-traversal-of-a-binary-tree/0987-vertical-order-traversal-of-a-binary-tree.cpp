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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue <pair<TreeNode*, pair<int,int>>> que;
        que.push({root, {0, 0}});
        
        map <int, multiset<pair<int,int>>> m;
        while(!que.empty()){
            int a = que.size();
            while(a--){
                TreeNode* node = que.front().first;
                int x = que.front().second.first, y = que.front().second.second;
                que.pop();
                m[x].insert({y, node->val});
                
                if(node->left){
                    que.push({node->left, {x-1, y+1}});
                }
                if(node->right){
                    que.push({node->right, {x+1, y+1}});
                }
            }
        }
        
        vector<vector<int>> ans;
        for(auto it : m){
            vector <int> cur;
            for(auto is : it.second){
                cur.push_back(is.second);
            }
            ans.push_back(cur);
        }
        
        return ans;
    }
};