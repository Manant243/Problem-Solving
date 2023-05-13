class Solution {
public:
    bool func(int ind, int size, int k, vector<int>subsets, vector<int>& nums){
        if(ind == nums.size()) return true;
        
        bool ok = false;
        for(int i = 0; i < k; i++){
            if(nums[ind] + subsets[i] <= size){
                subsets[i] += nums[ind];
                if(func(ind+1, size, k, subsets, nums)){
                    return true;
                }
                subsets[i] -= nums[ind];
                if(subsets[i] == 0){
                    return false;
                }
            }
        }
        
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        vector <int> subsets(k, 0);
        
        int size = 0;
        for(auto it : nums){
            size += it;
        }
        
        if(size%k != 0) return false;
        size /= k;
        
        sort(nums.rbegin(), nums.rend());
        if(func(0, size, k, subsets, nums)){
            return true;
        }
        
        return false;
    }
};