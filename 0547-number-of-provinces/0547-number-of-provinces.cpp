class Solution {
public:
    
    vector<int>parent;
    int find_parent(int node){
        if(parent[node] == -1) return node;
        return parent[node] = find_parent(parent[node]);
    }
    
    void u_merge(int i, int j){
        
        int p1 = find_parent(i);
        int p2 = find_parent(j);
        
        if(p1 == p2) return;
        parent[p1] = p2;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        parent.resize(n+1, -1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j]){
                    u_merge(i, j);
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(parent[i] == -1) ans++;
        }
        
        return ans;
    }
};