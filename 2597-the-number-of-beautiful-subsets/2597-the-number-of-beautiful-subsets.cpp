class Solution {
public:
    
    vector <int> cnt;
    int subsets(int index, vector<int>&nums, int k){
        if(index == nums.size()){
            return 1;
        }
        int taken = 0;
        if(nums[index] < k || cnt[nums[index]-k] == 0){
            cnt[nums[index]]++;
            taken = subsets(index+1, nums, k);
            cnt[nums[index]]--;
        }
        
        int nottaken = subsets(index+1, nums, k);
        return taken + nottaken;
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        cnt.resize(1001, 0);
        sort(nums.begin(), nums.end());
        
        return subsets(0, nums, k)-1;
    }
};