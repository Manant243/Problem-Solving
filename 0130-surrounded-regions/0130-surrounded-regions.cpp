class Solution {
public:
    
    int m = 0, n = 0;
    map <pair<int,int>, bool> vis;
    void dfs(int i, int j, vector<vector<char>>& board){
        if(vis[{i,j}]) return;
        vis[{i,j}] = true;
        if(i < 0 || j < 0 || i == m || j == n || board[i][j] == 'X') return;
        
        board[i][j] = '#';
        dfs(i+1, j, board);
        dfs(i, j+1, board);
        dfs(i-1, j, board);
        dfs(i, j-1, board);
    }
    
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        
        for(int i = 0; i < n; i++){
            dfs(0, i, board);
            dfs(m-1, i, board);
        }
        
        for(int i = 0; i < m; i++){
            dfs(i, 0, board);
            dfs(i, n-1, board);
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};