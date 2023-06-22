class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, pair<int,int>>, vector<pair<double, pair<int,int>>>, greater<pair<double, pair<int,int>>>> q;
        int n = points.size();
        
        for(int i = 0; i < n; i++){
            int a = points[i][0], b = points[i][1];
            int res = a*a + b*b;
            double cur = (double) sqrt(res);
            q.push({cur, {a, b}});
        }
        
        
        vector<vector<int>> ans;
        while(k--){
            pair<int,int> p = q.top().second;
            q.pop();
            vector<int>v = {p.first, p.second};
            ans.push_back(v);
        }
        
        return ans;
    }
};