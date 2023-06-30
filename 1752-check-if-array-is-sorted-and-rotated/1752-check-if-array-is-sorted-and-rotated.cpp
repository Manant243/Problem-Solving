class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size(), cnt = 0;
        for(int i = 1; i < n; i++){
            if(nums[i] <  nums[i-1]) cnt++;
        }
        
        if(nums[n-1] > nums[0]) cnt++;
        cout << cnt;
        return cnt <= 1;
    }
};