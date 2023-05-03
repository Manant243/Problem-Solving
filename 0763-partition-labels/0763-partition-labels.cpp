class Solution {
public:
    vector<int> partitionLabels(string s) {
        int maxi = 0, n = s.size();
        vector <int> ans;
        
        map <char, int> pos;
        for(int i = 0; i < n; i++){
            pos[s[i]] = i;
        }
        
        int cnt = 0;
        for(int i = 0; i < n; i++){
            cnt++;
            maxi = max(maxi, pos[s[i]]);
            if(i == maxi){
                ans.push_back(cnt); cnt = 0;
            }
        }
        
        return ans;
    }
};