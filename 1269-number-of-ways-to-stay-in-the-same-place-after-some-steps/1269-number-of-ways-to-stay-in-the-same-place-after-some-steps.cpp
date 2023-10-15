class Solution {
public:

    int mod = 1e9+7;
    int solve(int ind, int steps, int size, vector<vector<int>> &dp){
        if(ind == 0 && steps == 0) return 1;
        if(ind > steps || !steps) return 0;
        if(dp[ind][steps] != -1) return dp[ind][steps];
        
        int ans = 0;
        ans = (ans+solve(ind, steps-1, size, dp))%mod;
        if(ind < size-1){
            ans = (ans+solve(ind+1, steps-1, size, dp))%mod;
        }
        if(ind > 0){
            ans = (ans+solve(ind-1, steps-1, size, dp))%mod;
        }
        
        return dp[ind][steps] = ans%mod;
    }
    
    int numWays(int steps, int arrLen) {
        vector<vector<int>> dp(steps+1, vector<int>(steps+1, -1));
        
        int ans = solve(0, steps, arrLen, dp);
        return ans;
    }
};