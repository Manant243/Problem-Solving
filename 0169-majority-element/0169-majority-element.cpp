class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = 0, cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            if(cnt == 0){
                cnt++;
                ans = nums[i];
            }
            else if(nums[i] == ans){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return ans;
    }
};