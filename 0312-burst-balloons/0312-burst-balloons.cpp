class Solution {
public:
    
    int func(vector<int>& curr, int i, int j, vector<vector<int>>& dp){
        if(i == j){
            int temp = curr[i];
            if(i-1 >= 0) temp *= curr[i-1];
            if(i+1 < curr.size()) temp *= curr[i+1];
            
            return temp;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = 0;
        for(int k = i; k <= j; k++){
            int temp = curr[k];
            if(j+1 < curr.size()) temp *= curr[j+1];
            if(i-1 >= 0) temp *= curr[i-1];
            
            temp += func(curr, i, k-1, dp) + func(curr, k+1, j, dp);
            ans = max(ans, temp);
        }
        
        return dp[i][j] = ans;
    }
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector <int> curr = {1};
        
        for(auto it : nums){
            curr.push_back(it);
        }
        
        curr.push_back(1);
        vector<vector<int>> dp(501, vector<int>(501, -1));
        return func(curr, 1, curr.size()-2, dp);
    }
};