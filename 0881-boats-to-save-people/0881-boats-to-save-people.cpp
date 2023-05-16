class Solution {
public:
    int numRescueBoats(vector<int>& nums, int limit) {
        int n = nums.size();
        int ans = 0;
        
        sort(nums.begin(), nums.end());
        int j = n-1;
        
        map <int, bool> ok;
        for(int i = 0; i < n; i++){
            if(ok[i]) continue;
            if(i < j && nums[i] + nums[j] <= limit){
                ok[i] = true; ok[j] = true; j--;
            }
            else{
                while(i < j && nums[i] + nums[j] > limit){
                    j--;
                }
                if(i < j){
                    ok[i] = true; ok[j] = true; j--;
                }
            }
            ans++;
        }
        
        return ans;
    }
};