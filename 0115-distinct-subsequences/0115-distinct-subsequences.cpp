class Solution
{
public:
    
    int func(int a, int b, string& s, string& t, vector<vector<int>>& dp){
        if(b == t.size()) return 1;
        if(a == s.size()) return 0;
        if(dp[a][b] != -1) return dp[a][b];
        
        int ans = 0;
        ans += func(a+1, b, s, t, dp);
        
        if(s[a] == t[b]){
            ans += func(a+1, b+1, s, t, dp);
        }
        
        return dp[a][b] = ans;
    }
    
    int numDistinct(string &s, string &t){
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        
        return func(0, 0, s, t, dp);
    }
};