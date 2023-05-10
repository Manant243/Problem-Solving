class Solution {
public:
    vector<vector<int>> ans;
    void func(int ind, int sum, int n, int target, vector <int> current, vector <int>& candidates){
        if(sum == target){
            ans.push_back(current); return;
        }
        else if(sum > target) return;
        
        if(ind == n) return;
        
        // func(ind+1, sum, n, target, current, candidates);
        
        for(int i = ind; i < n; i++){
            sum += candidates[i];
            current.push_back(candidates[i]);
            func(i, sum, n, target, current, candidates);
            sum -= candidates[i];
            current.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size(), sum = 0;
        
        vector <int> current;
        func(0, 0, n, target, current, candidates);
        
        return ans;
    }   
    
};