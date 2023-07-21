class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector <int> dp(n+1, 0), curr(n+1, 0);
        
        int cur = 0;
        for(int i = 0; i < n; i++){
            dp[i] = 1, curr[i] = 1;
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    if(dp[j]+1 > dp[i]){
                        dp[i] = dp[j]+1;
                        curr[i] = curr[j];
                    }
                    else if(dp[j]+1 == dp[i]){
                        curr[i] += curr[j];
                    }
                }
            }
            cur = max(cur, dp[i]);
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(dp[i] == cur){
                ans += curr[i];
            }
        }
        
        return ans;
    }
};