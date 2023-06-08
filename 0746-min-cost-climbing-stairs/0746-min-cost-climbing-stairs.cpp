class Solution {
public:
    vector <int> dp;
    int func(int ind, vector <int>& cost){
        if(ind == cost.size()) return 0;
        if(dp[ind] != -1) return dp[ind];
        
        int ans = cost[ind];
        if(ind + 1 <= cost.size()){
            if(ind + 2 <= cost.size()){
                ans += min(func(ind+1, cost), func(ind+2, cost));
            }
            else{
                ans += func(ind+1, cost);
            }
        }
        
        
        return dp[ind] = ans;
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int ans = 0;
        dp.resize(cost.size()+1, -1);
        ans += min(func(0, cost), func(1, cost));
        
        return ans;
    }
};