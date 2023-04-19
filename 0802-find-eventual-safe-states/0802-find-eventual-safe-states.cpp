class Solution {
public:
    vector <bool> vis;
    vector <bool> check;
    vector <bool> cycle;

    bool dfs(int node, vector<vector<int>>& graph){
        vis[node] = true;
        cycle[node] = true;
        
        for(auto a : graph[node]){
            if(!vis[a]){
                if(!dfs(a, graph)){
                    return check[node] = false;
                }
            }
            else{
                if(cycle[a]){
                    return check[node] = false;
                }
            }
        }

        cycle[node] = false;    
        return true;    
    }   

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector <int> safe;

        cycle.resize(n+1, false);
        check.resize(n+1, true);
        vis.resize(n+1, false);

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, graph);
            }
        }

        for(int i = 0; i < n; i++){
            if(check[i]){
                safe.push_back(i);
            }
        }
        return safe;
    }
};