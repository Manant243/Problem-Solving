class Solution {
public:
    
    vector <int> dp;
    int func(int ind, int n, vector<int>&nums){
        if(ind >= n) return 0;
        if(dp[ind] != -1) return dp[ind];
        
        int ans = nums[ind];
        ans += max(func(ind+2, n, nums), func(ind+3, n, nums));
        
        dp[ind] = max(dp[ind], ans);
        
        return dp[ind];
    }
    
    int rob(vector<int>& nums) {
        int ans = 0, n = nums.size();
        dp.resize(n+1, -1);
        ans += max(func(0, n, nums), func(1, n, nums));
        
        return ans;
    }
};