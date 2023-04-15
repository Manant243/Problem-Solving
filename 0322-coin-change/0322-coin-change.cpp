class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector <int> dp(amount+5, 1e8);
        
        for(auto it : coins){
            if(it <= amount){
                dp[it] = 1;
            }
        }
        
        dp[0] = 0;
        sort(coins.begin(), coins.end());
        for(int i = 1; i <= amount; i++){
            for(int j = 0; j < n; j++){
                if(i - coins[j] < 0){
                    break;
                }
                else{
                    dp[i] = min(dp[i], dp[i-coins[j]]+1);
                }
            }
        }
        
        return dp[amount] == 1e8 ? -1 : dp[amount];
    }
};