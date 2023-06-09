class Solution {
public:
    
    int dfs(int ind, int amount, vector<int>&coins, vector<vector<int>>& dp){
        if(amount == 0) return 0;
        if(ind == coins.size()) return INT_MAX-1;
        if(dp[ind][amount] != -1) return dp[ind][amount];
        
        int ans = 0;
        if(amount >= coins[ind]){
            ans = min(dfs(ind+1, amount, coins, dp), dfs(ind, amount-coins[ind], coins, dp)+1);
        }
        else{
            ans = dfs(ind+1, amount, coins, dp);
        }
        
        return dp[ind][amount] = ans;
        
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector <int> (amount+1, -1));
        int ans = dfs(0, amount, coins, dp);
        
        return ans == INT_MAX-1 ? -1 : ans;
    }
};