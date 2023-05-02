class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        map <pair<int,int>, bool> vis;
        queue <pair<int,int>> q;
        
        int ans = 0, cnt = 0;
        int m = grid.size(), n = grid[0].size();
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({i,j}); cnt++;
                    vis[{i,j}] = true;
                }
                if(grid[i][j] == 0){
                    cnt++;
                }
            }
        }
        
        while(!q.empty()){
            
            int s = q.size(); 
            bool ok = false;
            
            while(s--){
                pair<int,int> k = q.front();
                int a = k.first, b = k.second; q.pop();
                
                if(grid[a][b] == 1) ok = true;
                if(a+1 < m && grid[a+1][b] == 1 && !vis[{a+1, b}]){
                    q.push({a+1,b}); vis[{a+1, b}] = true; cnt++;
                }
                if(a-1 >= 0 && grid[a-1][b] == 1 && !vis[{a-1, b}]){
                    q.push({a-1,b}); vis[{a-1, b}] = true; cnt++;
                }
                if(b+1 < n && grid[a][b+1] == 1 && !vis[{a, b+1}]){
                    q.push({a,b+1}); vis[{a, b+1}] = true; cnt++;
                }
                if(b-1 >= 0 && grid[a][b-1] == 1 && !vis[{a, b-1}]){
                    q.push({a,b-1}); vis[{a, b-1}] = true; cnt++;
                }
            }
            
            if(ok) ans++;
        }
        
        if(cnt != m*n){
            return -1;
        }
        
        return ans;
    }
};