class Solution {
public:
    set<vector<int>> ans;
    void func(int ind, int sum, int n, int target, vector <int> current, vector <int>& candidates){
        if(sum == target){
            ans.insert(current); return;
        }
        else if(sum > target) return;
        
        if(ind == n) return;
        
        func(ind+1, sum, n, target, current, candidates);
        
        sum += candidates[ind];
        current.push_back(candidates[ind]);
        func(ind, sum, n, target, current, candidates);
        func(ind+1, sum, n, target, current, candidates);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size(), sum = 0;
        
        vector <int> current;
        func(0, 0, n, target, current, candidates);
        
        vector<vector<int>> res;
        for(auto it : ans){
            res.push_back(it);
        }
        
        return res;
    }
};