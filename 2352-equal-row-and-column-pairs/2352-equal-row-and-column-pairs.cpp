class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map <vector<int>, int> rows;
        
        for(int i = 0; i < n; i++){
            rows[grid[i]]++;
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            vector <int> a;
            for(int j = 0; j < n; j++){
                a.push_back(grid[j][i]);
            }
            ans += rows[a];
        }
        
        return ans;
    }
};