class Solution {
public:
    
    int dfs(int i, int j, int m, int n, vector<vector<int>>& dp){
        if(i == m-1 && j == n-1){
            return 1;
        }
        if(i >= m || j >= n) return 0;
        
        if(dp[i][j] != 0){
            return dp[i][j];
        }
        
        int cnt = 0;
        cnt += dfs(i+1, j, m, n, dp);
        cnt += dfs(i, j+1, m, n, dp);
        
        return dp[i][j] = cnt;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        return dfs(0, 0, m, n, dp);
    }
};