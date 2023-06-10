class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto it : nums){
            sum += it;
        }
        
        if(sum&1) return false;
        sum /= 2;
        
        vector <int> dp(sum+1, 0);
        dp[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            for(int j = sum; j >= nums[i]; j--){
                dp[j] = dp[j] | dp[j-nums[i]];
            }
        }
        
        return dp[sum];
    }
};