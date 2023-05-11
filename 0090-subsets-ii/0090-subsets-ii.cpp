class Solution {
public:
    vector<vector<int>> ans;
    void func(int index, vector<int>current, vector<int>& nums){
        if(index == nums.size()){
            return;
        }
        
        int ind = index;
        while(ind < nums.size()-1 && nums[ind] == nums[ind+1]){
            ind++;
        }
        
        func(ind+1, current, nums);
        current.push_back(nums[index]);
        ans.push_back(current);
        func(index+1, current, nums);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums){
        vector <int> current;
        ans.push_back(current);
        
        sort(nums.begin(), nums.end());
        func(0, current, nums);
        
        return ans;
    }
};