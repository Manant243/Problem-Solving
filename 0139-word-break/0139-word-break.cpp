class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector <bool> dp(n+1, false);
        dp[n] = true;
        
        map <string,int> cnt;
        for(auto it : wordDict){
            cnt[it]++;
        }
        
        for(int i = n-1; i >= 0; i--){
            string k;
            for(int j = i; j < n; j++){
                k += s[j];
                if(cnt.count(k) && dp[j+1]){
                    dp[i] = true;
                }
            }
        }
        
        return dp[0];
    }
};


