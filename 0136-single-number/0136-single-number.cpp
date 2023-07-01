class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size(), cur = 0;
        for(int i = 0; i < n; i++){
            cur ^= nums[i];
        }
        return cur;
    }
};