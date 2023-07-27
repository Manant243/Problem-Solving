class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        map <int, vector<pair<int,int>>> adj;      
        for(auto is : flights){
            adj[is[0]].push_back({is[1], is[2]});
        }
        
        queue <pair<int, pair<int,int>>> que;
        
        vector <int> dis(n, 1e9);
        dis[src] = 0;
        
        que.push({0, {src, 0}});
        while(!que.empty()){
            auto it = que.front();
            que.pop();
            
            int stops = it.first;
            int node = it.second.first;
            int dist = it.second.second;
            
            if(node == dst || stops > k) continue;
            
            for(auto is : adj[node]){
                int adjNode = is.first;
                int weight = is.second;
                if(dist + weight < dis[adjNode] && stops <= k){
                    dis[adjNode] = dist + weight;
                    que.push({stops+1, {adjNode, dis[adjNode]}});
                }
            }
        }
        
        if(dis[dst] == 1e9) return -1;
        return dis[dst];
    }
};