class Solution {
public:
    vector<vector<int>> ans;
    void func(int ind, int n, int target, vector <int> current, vector <int>& candidates){
        if(target == 0){
            ans.push_back(current); return;
        }
        if(target < 0) return;
        
        for(int i = ind; i < n; i++){
            current.push_back(candidates[i]);
            func(i, n, target-candidates[i], current, candidates);
            current.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size(), sum = 0;
        
        vector <int> current;
        func(0, n, target, current, candidates);
        
        return ans;
    }   
    
};