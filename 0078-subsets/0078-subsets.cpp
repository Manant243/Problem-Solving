class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int ind, int n, vector <int> v, vector <int>& nums){
        if(ind == n) return;
        dfs(ind+1, n, v, nums);
        v.push_back(nums[ind]);
        ans.push_back(v);
        dfs(ind+1, n, v, nums);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        ans.push_back({});
        
        int n = nums.size();
        for(int i = 0; i < n; i++){
            vector <int> v;
            v.push_back(nums[i]);
            ans.push_back(v);
            dfs(i+1, n, v, nums);
        }
        
        return ans;
    }
};