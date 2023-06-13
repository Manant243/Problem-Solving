class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map <vector<int>, int> rows, columns;
        vector<vector<int>> row, column;
        
        for(int i = 0; i < n; i++){
            vector <int> r, c;
            for(int j = 0; j < n; j++){
                r.push_back(grid[i][j]);
                c.push_back(grid[j][i]);
            }
            row.push_back(r);
            column.push_back(c);
            rows[r]++; columns[c]++;
        }
        
        int ans = 0;
        for(int i = 0; i < row.size(); i++){
            vector<int>r = row[i];
            ans += columns[r];
            
            vector<int>c = column[i];
            ans += rows[c];
        }
        
        ans /= 2;
        return ans;
    }
};