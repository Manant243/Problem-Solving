class Solution {
public:
    
    vector <int> ans;
    map <int, vector<int>> adj;
    bool cycle(int node, vector <int>& vis){
        vis[node] = 1;
        
        for(auto it : adj[node]){
            if(vis[it] == 1) return true;
            if(vis[it] == 0){
                if(cycle(it, vis)) return true;
            }
        }
        
        vis[node] = 2;
        ans.push_back(node);
        return false;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites){
        int n = numCourses;
        
        for(auto it : prerequisites){
            adj[it[0]].push_back(it[1]);
        }
        
        vector <int> vis(n+1, 0);
        for(int i = 0; i < n; i++){
            if(vis[i] == 0){
                if(cycle(i, vis)) return {};
            }
        }
        
        return ans;
    }
    
};