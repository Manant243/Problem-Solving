class Solution {
public:
    
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX, sum = 0, left = 0;
        
        for(int i = 0; i < n; i++){
            sum += nums[i];
            while(sum >= target){
                ans = min(ans, i-left+1);
                sum -= nums[left++];
            }
        }
        
        return (ans != INT_MAX ? ans : 0);
    }
};