class Solution {
public:
    
    int dfs(int i, int j, pair<int,int> p, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        int left = 0, right = 0, up = 0, down = 0;
        if(dp[i][j]) return dp[i][j];
        
        if(p.first != i-1 || p.second != j){
            if(i-1 >= 0 && matrix[i-1][j] > matrix[i][j]){
                up += dfs(i-1, j, {i, j}, matrix, dp)+1;
            }
        }
        if(p.first != i || p.second != j-1){
            if(j-1 >= 0 && matrix[i][j-1] > matrix[i][j]){
                left += dfs(i, j-1, {i, j}, matrix, dp)+1;
            }   
        }
        if(p.first != i+1 || p.second != j){
            if(i+1 < matrix.size() && matrix[i+1][j] > matrix[i][j]){
                down += dfs(i+1, j, {i, j}, matrix, dp)+1;
            }
        }
        if(p.first != i || p.second != j+1){
            if(j+1 < matrix[0].size() && matrix[i][j+1] > matrix[i][j]){
                right += dfs(i, j+1, {i, j}, matrix, dp)+1;
            }
        }
        
        return dp[i][j] = max({up, down, left, right});
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        pair <int,int> p = {-1, -1};
        int ans = 0;
        
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size()+1, 0));
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                ans = max(ans, dfs(i, j, p, matrix, dp)+1);
            }
        }
        
        return ans;
    }
};