class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        map <int, pair<int,int>> pos;
        vector <int> columns(n);
        vector <int> dist(n*n+1, -1);
        
        int level = 1; dist[1] = 0;
        iota(columns.begin(), columns.end(), 0);
        for(int i = n-1; i >= 0; i--){
            for(auto it : columns){
                pos[level++] = {i, it};
            }
            reverse(columns.begin(), columns.end());
        }
        
        queue <int> q; q.push(1);
        while(!q.empty()){
            int curr = q.front(); q.pop();

            for(int next = curr+1; next <= min(curr + 6, n*n); next++){
                auto [row, column] = pos[next];
                int destination = 0;
                destination = (board[row][column] != -1 ? board[row][column] : next);
                
                if(dist[destination] == -1){
                    dist[destination] = dist[curr]+1;
                    q.push(destination);
                }
            }
        }
        
        return dist[n*n];
    }
};