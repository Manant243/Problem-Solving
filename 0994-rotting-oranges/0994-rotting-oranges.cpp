class Solution {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue <pair<int,int>> q;
        
        int ans = 0, cnt = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dis(m, vector<int>(n, -1));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2 || grid[i][j] == 0){
                    if(grid[i][j] == 2) q.push({i,j});
                    dis[i][j] = 0;
                }
            }
        }
        
        while(!q.empty()){
            pair<int,int> a = q.front();
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int x = a.first+dx[i];
                int y = a.second+dy[i];
                if(x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == 1 && dis[x][y] == -1){
                    dis[x][y] = dis[a.first][a.second]+1;
                    q.push({x, y});
                }
            }
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(dis[i][j] == -1) return -1;
                ans = max(ans, dis[i][j]);
                cout << dis[i][j] << " ";
            }
            cout << "\n";
        }
        
        return ans;
    }
};