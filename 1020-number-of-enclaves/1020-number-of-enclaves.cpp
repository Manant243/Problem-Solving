class Solution {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
public:
    map<pair<int,int>, bool> okay;

    int dfs(int i, int j, int m, int n, vector<vector<int>>& grid){
        if(okay[{i, j}]){
            return 0;
        }

        okay[{i, j}] = 1;
        int ans = 0;

        for(int k = 0; k < 4; k++){
            int x = i+dx[k];
            int y = j+dy[k];
            if(x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == 1){
                ans += dfs(x, y, m, n, grid);
            }
        }

        return ans+1;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) cnt++;
            }
        }

        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!okay[{i,j}] && grid[i][j] == 1 && (i == 0 || j == 0 || i == m-1 || j == n-1)){
                    ans += dfs(i, j, m, n, grid);
                }
            }
        }

        return cnt-ans;
    }
};