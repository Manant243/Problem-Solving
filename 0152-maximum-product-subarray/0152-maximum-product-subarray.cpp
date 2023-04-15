class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int mini = 1, maxi = 1, ans = -1e9;
        
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                mini = 1; maxi = 1;
            }
            int temp = maxi*nums[i];
            maxi = max({nums[i], maxi*nums[i], mini*nums[i]});
            mini = min({nums[i], temp, mini*nums[i]});
            
            ans = max(ans, maxi);
        }
        
        return ans;
    }
};