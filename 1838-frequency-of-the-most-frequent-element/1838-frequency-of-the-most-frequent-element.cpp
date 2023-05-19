class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int i = 1, j = 0, ans = 1, n = nums.size();
        while(i < n){
            long sup = long(nums[i]-nums[i-1])*(i-j);
            if(sup <= k){
                k -= (nums[i]-nums[i-1])*(i-j);
                ans = max(ans, i-j+1);
            }
            else{
                long sup = long(nums[i]-nums[i-1])*(i-j);
                while(j < i && sup > k){
                    k += (nums[i-1]-nums[j]); j++;
                    sup = long(nums[i]-nums[i-1])*(i-j);
                }
                if(j == i) i++;
                continue;
            }
            i++;
        }
        
        return ans;
    }
};