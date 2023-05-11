class Solution {
public:
    vector<vector<int>> ans;
    
    void func(int ind, vector<int> nums){
        if(ind == nums.size()){
            ans.push_back(nums); return;
        }
        
        for(int i = ind; i < nums.size(); i++){
            if(i != ind && nums[i] == nums[ind]) continue;
            swap(nums[i], nums[ind]);
            func(ind+1, nums);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        func(0, nums);
        
        return ans;
    }
};