class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int i = 1, j = 0, ans = 1, n = nums.size();
        while(i < n){
            if(long(nums[i]-nums[i-1])*(i-j) <= k){
                k -= (nums[i]-nums[i-1])*(i-j);
                ans = max(ans, i-j+1);
            }
            else{
                while(j < i && long(nums[i]-nums[i-1])*(i-j) > k){
                    k += (nums[i-1]-nums[j]); j++;
                }
                if(j == i) i++;
                continue;
            }
            i++;
        }
        
        return ans;
    }
};