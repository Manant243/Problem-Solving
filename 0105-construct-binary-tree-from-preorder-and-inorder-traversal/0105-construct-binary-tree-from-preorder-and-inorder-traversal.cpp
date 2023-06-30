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
    map <int,int> pos;
    
    int k;
    TreeNode* func(int l1, int r1, int l2, int r2, vector<int>& preorder, vector<int>& inorder){
        if(l1 > r1 || l2 > r2) return NULL;
        TreeNode* root = new TreeNode(preorder[l2]);
        
        int inroot = pos[root->val];
        int left = inroot-l1;
        
        root->left = func(l1, inroot-1, l2+1, l2+left, preorder, inorder);
        root->right = func(inroot+1, r1, l2+left+1, r2, preorder, inorder);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for(int i = 0; i < (preorder.size()); i++){
            pos[inorder[i]] = i;
        }
        k = preorder.size()-1;
        TreeNode* root = func(0, k, 0, k, preorder, inorder);
        return root;
    }
};