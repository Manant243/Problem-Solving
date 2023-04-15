class Solution {
public:
    int partitionString(string s) {
        int n = s.size();
        vector <int> v(26, 0);
        
        int ans = 1;
        for(int i = 0; i < n; i++){
            if(v[s[i] - 'a']){
                ans++;
                for(int i = 0; i < 26; i++){
                    v[i] = 0;
                }
            }
            v[s[i] - 'a']++;
        }
        
        return ans;
    }
};