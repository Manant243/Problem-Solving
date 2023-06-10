class Solution {
public:
    bool dfs(int target, int ind, vector<int>&nums, vector<vector<int>>& dp){
        if(target == 0) return true;
        if(ind < 0) return false;
        if(dp[ind][target] != -1) return dp[ind][target];
        
        bool ok = false;
        ok |= dfs(target, ind-1, nums, dp);
        if(target >= nums[ind]){
            ok |= dfs(target-nums[ind], ind-1, nums, dp);
        }
        
        return dp[ind][target] = ok;
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto it : nums){
            sum += it;
        }
        
        if(sum&1) return false;
        sum /= 2;
        
        vector<vector<int>> dp(nums.size()+1, vector<int>(sum+1, -1));
        return dfs(sum, nums.size()-1, nums, dp);
    }
};