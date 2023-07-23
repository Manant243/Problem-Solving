/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map <TreeNode*, TreeNode*> m;
        queue <TreeNode*> que;
        
        que.push(root);
        while(!que.empty()){
            int a = que.size();
            while(a--){
                TreeNode* curr = que.front();
                que.pop();
                if(curr->left){
                    que.push(curr->left);
                    m[curr->left] = curr;
                }
                if(curr->right){
                    que.push(curr->right);
                    m[curr->right] = curr;
                }
            }
        }
        
        queue <TreeNode*> q;
        q.push(target);
        
        int cnt = 0;
        vector <int> ans;
        map <TreeNode*, bool> vis;
        vis[target] = true;
        
        while(!q.empty()){
            int a = q.size();
            if(cnt == k){
                while(!q.empty()){
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                break;
            }
            while(a--){
                TreeNode* curr = q.front();
                vis[curr] = true;
                q.pop();
                if(curr->left && !vis[curr->left]){
                    q.push(curr->left);
                }
                if(curr->right && !vis[curr->right]){
                    q.push(curr->right);
                }
                if(m[curr] && !vis[m[curr]]){
                    q.push(m[curr]);
                }
            }
            cnt++;
        }
    
        return ans;
    }
};