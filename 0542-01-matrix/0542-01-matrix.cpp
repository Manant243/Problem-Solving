class Solution {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dis(m, vector<int>(n, -1));
        
        queue<pair<int,int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    q.push({i, j});
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
                if(x >= 0 && y >= 0 && x < m && y < n && mat[x][y] == 1 && dis[x][y] == -1){
                    dis[x][y] = dis[a.first][a.second]+1;
                    q.push({x, y});
                }
            }
        }
        
        return dis;
    }
};