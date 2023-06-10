class Solution {
public:
    
    int func(int a, int b, string& text1, string& text2, vector<vector<int>>& dp){
        if(a >= text1.size() || b >= text2.size()) return 0;
        if(dp[a][b] != -1) return dp[a][b];
        
        int ans = 0;
        if(text1[a] == text2[b]){
            ans += func(a+1, b+1, text1, text2, dp)+1;
        }
        else{
            ans += max({func(a+1, b, text1, text2, dp), func(a, b+1, text1, text2, dp), func(a+1, b+1, text1, text2, dp)});
        }
        
        return dp[a][b] = ans;
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        
        return func(0, 0, text1, text2, dp);
    }
};