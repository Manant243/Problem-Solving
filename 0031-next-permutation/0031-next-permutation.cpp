class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return;
        
        int i = n-1, j = n-1;
        
        while (i > 0 && nums[i-1] >= nums[i]) i--;
        
        if (i == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        i--;
        while (j > i && nums[j] <= nums[i]) j--;
        
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
    }
};