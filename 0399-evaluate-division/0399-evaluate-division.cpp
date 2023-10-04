class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map <string, vector<pair<string,double>>> adj;
        int n = equations.size();
        
        for(int i = 0; i < n; i++){
            string temp1 = equations[i][0];
            string temp2 = equations[i][1];
            adj[temp1].push_back({temp2, values[i]});
            adj[temp2].push_back({temp1, 1/values[i]});
        }
        
        vector <double> result;
        for(int i = 0; i < queries.size(); i++){
            vector<string>temp = queries[i];
            if(temp[0] == temp[1] && adj[temp[0]].size()){
                double d = 1.0;
                result.push_back(d);
                continue;
            }
            queue<pair<string, double>> que;
            map <string, bool> vis;
            
            que.push({temp[0], 1});
            bool ok = false;
            while(!que.empty()){
                int a = que.size();
                while(a--){
                    auto it = que.front(); que.pop();
                    vis[it.first] = true;
                    for(auto is : adj[it.first]){
                        if(is.first == temp[1]){
                            ok = true;
                            result.push_back(it.second*is.second);
                            break;
                        }
                        else if(!vis[is.first]){
                            que.push({is.first, it.second*is.second});
                        }
                    }
                    if(ok) break;
                }
                if(ok) break;
            }
            if(!ok){
                double d = -1.0;
                result.push_back(d);
            }
        }
        
        return result;
    }
};