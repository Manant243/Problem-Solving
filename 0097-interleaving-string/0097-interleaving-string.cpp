class Solution {
public:
    
    bool func(int ind, int ind1, int ind2, string& s1, string& s2, string& s3, vector<vector<int>>& dp){
        if(ind == s3.size() && ind1 == s1.size() && ind2 == s2.size()) return 1;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        
        bool ok  = false;
        if(ind1 < s1.size() && s1[ind1] == s3[ind]){
            ok |= func(ind+1, ind1+1, ind2, s1, s2, s3, dp);
        }
        if(ind2 < s2.size() && s2[ind2] == s3[ind]){
            ok |= func(ind+1, ind1, ind2+1, s1, s2, s3, dp);
        }
        
        return dp[ind1][ind2] = ok;
        
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int a = s1.size(), b = s2.size();
        vector<vector<int>> dp(a+1, vector<int>(b+1, -1));
        
        return func(0, 0, 0, s1, s2, s3, dp) | func(0, 0, 0, s1, s2, s3, dp);
    }
};