class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> mp;
        vector<int> ans;
        for(auto p : adjacentPairs) {
            mp[p[0]].push_back(p[1]);            
            mp[p[1]].push_back(p[0]);                            
        }
        for(auto m : mp) {
            if(m.second.size() == 1) {
                ans.push_back(m.first);
                ans.push_back(m.second[0]);
                break;
            }
        }
        vector<int> vec = mp[ans[ans.size()-1]];
        while(vec.size() != 1) {
            if(vec[0] != ans[ans.size()-2]) {
                ans.push_back(vec[0]);
            } else {
                ans.push_back(vec[1]);                
            }
            vec = mp[ans[ans.size()-1]];
        }
        return ans;
    }
};