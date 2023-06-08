class Solution {
public:
    
    int climbStairs(int n) {
        int ans = 0;
        vector <int> dp(n+1, 0);
        
        dp[0] = 1;
        for(int i = 1; i <= n; i++){
            dp[i] += dp[i-1];
            if(i-2 >= 0) {
                dp[i] += dp[i-2];
            }
        }
        
        return dp[n];
    }
};