class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int n = nums.size(), cnt = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                cnt++;
            }
        }
        
        int k = 0, cur = n-cnt, j = 0;
        for(int i = 0; i < n && j < cur; i++){
            if(nums[i]){
                nums[k] = nums[i]; k++; j++;
            }
        }
        
        while(cnt--){
            nums[k] = 0; k++;
        }
    }
};