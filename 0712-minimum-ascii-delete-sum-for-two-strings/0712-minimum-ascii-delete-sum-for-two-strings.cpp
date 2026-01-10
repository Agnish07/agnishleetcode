class Solution {
public:
    int fn(string &s1, string &s2, vector<vector<int>> &dp, int m, int n){
        if(dp[m][n] != -1) return dp[m][n];

        if(m == s1.size() && n == s2.size()) return dp[m][n] = 0;
        if(m == s1.size()) return dp[m][n] = s2[n] + fn(s1, s2, dp, m, n+1);
        if(n == s2.size()) return dp[m][n] = s1[m] + fn(s1, s2, dp, m+1, n);

        if(s1[m] == s2[n]) return dp[m][n] = fn(s1,s2,dp,m+1,n+1);

        return dp[m][n] = min(
            s2[n] + fn(s1, s2, dp, m, n+1),
            s1[m] + fn(s1, s2, dp, m+1, n)
        );
    }
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return fn(s1,s2,dp,0,0);
    }
};