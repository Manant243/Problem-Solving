class Solution {
public:
    
    vector <int> dp;
    int dfs(int ind, int n){
        if(ind == n) return 1;
        if(dp[ind] != -1) return dp[ind];
            
        int ans = 0;
        if(ind + 1 <= n){
            ans += dfs(ind+1, n);
        }
        
        if(ind + 2 <= n){
            ans += dfs(ind+2, n);
        }
        
        return dp[ind] = ans;
    }
    
    int climbStairs(int n) {
        int ans = 0;
        dp.resize(n+1, -1);
        ans += dfs(1, n);
        if(n > 1) ans += dfs(2, n);
        
        return ans;
    }
};