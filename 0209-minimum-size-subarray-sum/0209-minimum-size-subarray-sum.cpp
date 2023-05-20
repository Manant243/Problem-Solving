class Solution {
public:
    bool check(int mid, int target, vector<int>& nums){
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(i == mid-1){
                if(sum >= target) return true;
            }
            if(i > mid-1){
                sum -= nums[i-mid];
                if(sum >= target) return true;
            }
        }
        return false;
    }
    
    int minSubArrayLen(int target, vector<int>& nums) {
        int low = 0, high = nums.size(), ans = 0;
        while(low <= high){
            int mid = (low + high)/2;
            if(check(mid, target, nums)){
                high = mid-1; ans = mid;
            }
            else{
                low = mid+1;
            }
        }
        
        return ans;
    }
};