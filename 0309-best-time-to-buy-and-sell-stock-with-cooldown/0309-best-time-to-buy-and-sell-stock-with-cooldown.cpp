class Solution {
public:
    int profit(int ind, bool buy, vector<int>& prices, vector<vector<int>>& dp){
        if(ind >= prices.size()) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        
        //ignore the transaction
        int ans = 0;
        ans = profit(ind+1, buy, prices, dp);
        
        if(buy){
            ans = max(ans, profit(ind+1, 0, prices, dp) - prices[ind]);
        }
        else{
            ans = max(ans, profit(ind+2, 1, prices, dp) + prices[ind]);
        }
        
        return dp[ind][buy] = ans;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector <int> (2, -1));
        
        return profit(0, 1, prices, dp);
    }
};