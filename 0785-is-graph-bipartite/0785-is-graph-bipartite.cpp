class Solution {
public:
    
    bool dfs(int node, int color, int parent, vector<int>& vis, vector<vector<int>>& graph){
        vis[node] = color;
        for(auto it : graph[node]){
            if(!vis[it]){
                bool ok = dfs(it, 3-color, node, vis, graph);
                if(!ok) return false;
            }
            else if(it != parent && vis[it] == color){
                return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector <int> vis(n, 0);
        
        for(int i = 0; i < n; i++){
            if(!vis[i] && !dfs(i, 1, -1, vis, graph)){
                return false;
            }
        }
        
        return true;
    }
};