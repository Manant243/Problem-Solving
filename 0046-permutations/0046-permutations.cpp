class Solution {
public:
    
    map <int,bool> present;
    vector<vector<int>> permutations;
    
    void func(int count, int n, vector<int>& current, vector<int>& nums){
        if(count == nums.size()){
            cout << count << " ";
            permutations.push_back(current); 
            return;
        };
        
        for(int i = 0; i < n; i++){
            if(!present[nums[i]]){
                present[nums[i]] = true;
                current.push_back(nums[i]);
                func(count+1, n, current, nums);
                present[nums[i]] = false;
                current.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector <int> current;
        func(0, n, current, nums);
        return permutations;
    }
};