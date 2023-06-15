class Solution {
public:
    
    int func(int ind1, int ind2, string& word1, string& word2, vector<vector<int>>& dp){
        if(ind2 == word2.size()){
            return word1.size()-ind1;
        }
        if(ind1 == word1.size()){
            return word2.size()-ind2;
        }
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        
        int ans = 0;
        if(ind1 < word1.size()){
            if(word1[ind1] == word2[ind2]){
                ans += func(ind1+1, ind2+1, word1, word2, dp);
            }
            else{
                ans += min({func(ind1+1, ind2, word1, word2, dp),
                           func(ind1, ind2+1, word1, word2, dp),
                           func(ind1+1, ind2+1, word1, word2, dp)})+1;
            }
        }
        
        return dp[ind1][ind2] = ans;
    }
    
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        
        return func(0, 0, word1, word2, dp);
    }
};