class Solution {
public:
    map<int,vector<int>> adj;
    int dfs(int node, vector<int>& informTime){
        int ans = 0;
        bool ok = false;
        for(auto a : adj[node]){
            ok = true;
            ans = max(ans,dfs(a, informTime));
        }
        if(ok){
            return (ans+informTime[node]);
        }
        return 0;
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        for(int i = 0; i < n; i++){
            if(manager[i] != -1){
                adj[manager[i]].push_back(i);
            }
        }
        return dfs(headID, informTime);
    }
};