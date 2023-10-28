class Solution {
public:

    int mod = 1e9+7;

    int countVowelPermutation(int n) {
        int dp[n+1][26];
        memset(dp, 0, sizeof(dp));

        char a = 'a', e = 'e', i = 'i', o = 'o', u = 'u';
        dp[0][a-'a'] = 1; dp[0][e-'a'] = 1;
        dp[0][i-'a'] = 1; dp[0][o-'a'] = 1; dp[0][u-'a'] = 1;

        for(int j = 1; j < n; j++){
            dp[j][o-'a'] = (dp[j-1][i-'a'])%mod;
            dp[j][i-'a'] = (dp[j-1][e-'a'] + dp[j-1][o-'a'])%mod;
            dp[j][e-'a'] = (dp[j-1][a-'a'] + dp[j-1][i-'a'])%mod;
            dp[j][u-'a'] = (dp[j-1][o-'a'] + dp[j-1][i-'a'])%mod;
            dp[j][a-'a'] = ((dp[j-1][e-'a'] + dp[j-1][i-'a'])%mod + dp[j-1][u-'a'])%mod;
        }

        int ans = (((dp[n-1][a-'a']+dp[n-1][e-'a'])%mod+(dp[n-1][i-'a']+dp[n-1][o-'a'])%mod)%mod+dp[n-1][u-'a'])%mod;
        return ans;
    }
};