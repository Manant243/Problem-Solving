class Solution {
public:
    vector<vector<int>> ans;
    void func(int curr, int n, int k, vector <int> current){
        if(k == 0){
            ans.push_back(current); return;
        }
        
        for(int i = curr+1; i <= n; i++){
            current.push_back(i);
            func(i, n, k-1, current);
            current.pop_back();
        }
        
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> current;
        func(0, n, k, current);
        
        return ans;
    }
};