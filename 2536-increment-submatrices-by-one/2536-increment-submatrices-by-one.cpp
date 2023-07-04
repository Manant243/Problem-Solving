class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> pref(n, vector<int>(n, 0));
        
        for(int i = 0; i < queries.size(); i++){
            int a = queries[i][0], b = queries[i][1];
            int c = queries[i][2], d = queries[i][3];
            
            pref[a][b]++;
            if(c+1 < n) pref[c+1][b]--;
            if(d+1 < n) pref[a][d+1]--;
            if(c+1 < n && d+1 < n) pref[c+1][d+1]++;
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(j-1 >= 0) pref[i][j] += pref[i][j-1];
                if(i-1 >= 0) pref[i][j] += pref[i-1][j];
                if(i > 0 && j > 0) pref[i][j] -= pref[i-1][j-1];
            }
        }
        
        return pref;
    }
};