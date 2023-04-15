class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '0'){
                    continue;
                }
                dp[i][j] = 1;
            }
        }
        
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(matrix[i][j] == '0'){
                    continue;
                }
                if(i+1 < m && j+1 < n){
                    dp[i][j] += min({dp[i+1][j], dp[i][j+1], dp[i+1][j+1]});
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans = max(ans, dp[i][j]*dp[i][j]);
            }
        }
        
        return ans;
    }
};