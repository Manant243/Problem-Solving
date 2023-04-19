class Solution {
public:
    map <int,vector<int>> adj;
    vector <bool> vis;

    void dfs(int x){
        if(vis[x]) return;
        vis[x] = true;

        for(auto a : adj[x]){
            dfs(a);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vis.resize(n+1, 0);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < rooms[i].size(); j++){
                adj[i].push_back(rooms[i][j]);
            }
        }

        dfs(0);
        for(int i = 0; i < n; i++){
            if(!vis[i]) return false;
        }

        return true;
    }
};