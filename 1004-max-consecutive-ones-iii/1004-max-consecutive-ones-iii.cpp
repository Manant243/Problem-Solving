class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        
        int zero = 0, j = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0) zero++;
            while(j <= i && zero > k){
                if(nums[j] == 0) zero--; j++;
            }
            ans = max(ans, i-j+1);
        }
        
        return ans;
    }
};