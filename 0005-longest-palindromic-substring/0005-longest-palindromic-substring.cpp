class Solution {
public:
    
    string longestPalindrome(string s) {
        int n = s.size();
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        int l = 0, ans = 1;
        for(int i = 0; i < n; i++){
            dp[i][i] = 1;
            for(int j = 0; j < i; j++){
                dp[j][i] = (s[i] == s[j] && (i-j < 2 || dp[j+1][i-1]));
                if(dp[j][i] && i-j+1 > ans){
                    ans = i-j+1; l = j;
                }
            }
        }
        
        
        string k = s.substr(l, ans);
        return k;
    }
};