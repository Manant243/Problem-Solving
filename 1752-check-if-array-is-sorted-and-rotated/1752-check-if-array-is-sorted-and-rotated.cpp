class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size(), i = 0;
        bool ok = true;
        
        while(i < n-1 && nums[i] <= nums[i+1]){
            i++;
        }
        
        if(i == n) return true;
        i++;
        while(i < n){
            if(nums[i] > nums[0]){
                ok = false; break;
            }
            if(i < n-1 && nums[i+1] > nums[0]){
                ok = false; break;
            }
            if(i < n-1 && nums[i+1] < nums[i]){
                ok = false; break;
            }
            i++;
        }
        if(!ok || i != n) return false;
        return true;
    }
};