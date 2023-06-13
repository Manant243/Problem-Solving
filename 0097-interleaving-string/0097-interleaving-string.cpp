class Solution {
public:
    
    bool isInterleave(string s1, string s2, string s3) {
        int a = s1.size(), b = s2.size();
        if(a+b != s3.size()) return false;
        
        vector<vector<bool>> dp(a+1, vector<bool>(b+1, 0));
        
        dp[0][0] = true;
        for(int i = 0; i <= a; i++){
            for(int j = 0; j <= b; j++){
                if(i == 0 && j == 0) continue;
                if(i == 0){
                    dp[i][j] = (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
                }
                else if(j == 0){
                    dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]);
                }
                else{
                    dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]) | (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
                }
            }
        }
        
        return dp[a][b];
    }
};