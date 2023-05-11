class Solution {
public:
    vector<vector<int>> ans;
    void func(int ind, int target, vector<int>current, vector<int>& candidates){
        if(target < 0 || (ind == candidates.size() && target > 0)) return;
        if(target == 0){
            ans.push_back(current); return;
        }
        
        int index = ind;
        while(index < candidates.size()-1 && candidates[index] == candidates[index+1]){
            index++;
        }
        func(index+1, target, current, candidates);
        
        target -= candidates[ind];
        current.push_back(candidates[ind]);
        func(ind+1, target, current, candidates);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int>current;
        
        sort(candidates.begin(), candidates.end());
        func(0, target, current, candidates);
        
        return ans;
    }
};