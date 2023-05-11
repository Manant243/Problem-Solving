class Solution {
public:
    vector<vector<int>> ans;
    map <int,int> cnt;
    
    void func(int n, vector<int>& current){
        if(current.size() == n){
            ans.push_back(current); return;
        }
        
        for(auto it : cnt){
            if(it.second >= 1){
                cnt[it.first]--;
                current.push_back(it.first);
                func(n, current);
                cnt[it.first]++;
                current.pop_back();
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector <int> current;
        
        for(auto it : nums){
            cnt[it]++;
        }
        
        int n = nums.size();
        func(n, current);
        
        return ans;
    }
};