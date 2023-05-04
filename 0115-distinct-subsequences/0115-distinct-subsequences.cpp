class Solution
{
public:
    int dp[1001][1001];
    int solve(string &s, string &t, int i, int j)
    {
        if (j == t.length())
        {
            return 1;
        }
        if (i == s.length())
        {
            return 0;
        }
        else if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        else if (s[i] == t[j])
        {
            return dp[i][j] = solve(s, t, i + 1, j + 1) + solve(s, t, i + 1, j);
        }
        else
        {
            return dp[i][j] = solve(s, t, i + 1, j);
        }
    }
    int numDistinct(string &s, string &t)
    {
        memset(dp, -1, sizeof(dp));
        return solve(s, t, 0, 0);
    }
};