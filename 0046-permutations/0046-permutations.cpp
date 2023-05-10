class Solution {
public:
    vector<vector<int>> ans;
    map <int, bool> visited;
    
    void func(int cnt, vector <int> current, vector <int>& nums){
        if(cnt == nums.size()){
            ans.push_back(current); return;
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(!visited[nums[i]]){
                current.push_back(nums[i]);
                visited[nums[i]] = true;
                func(cnt+1, current, nums);
                visited[nums[i]] = false;
                current.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector <int> current;
    
        for(int i = 0; i < nums.size(); i++){
            current.push_back(nums[i]);
            visited[nums[i]] = true;
            func(1, current, nums);
            current.pop_back();
            visited[nums[i]] = false;
        }
        
        return ans;
    }
};