class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector <int> dp(n+1, 0);
        dp[n] = 1;
        
        for(int i = n-1; i >= 0; i--){
            if(s[i] == '0'){
                dp[i] = 0; continue;
            }
            dp[i] = dp[i+1];
            if(i < n-1 && (s[i] < '2' || (s[i] == '2' && s[i+1] < '7'))){
                dp[i] += dp[i+2];
            }
        }
        
        return dp[0];
    }
};