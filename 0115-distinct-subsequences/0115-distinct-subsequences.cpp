class Solution {
public:
    // int fn(string &s, string &t, int i, int j, vector<vector<int>> &dp){
    //     if(j < 0) return 1;
    //     if(i < 0) return 0;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     if(s[i] == t[j]){
    //         return dp[i][j] = fn(s,t,i-1,j-1,dp) + fn(s,t,i-1,j,dp);
    //     }
    //     return dp[i][j] = fn(s,t,i-1,j,dp);
    // }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        // vector<vector<unsigned long long>> dp(n+1, vector<unsigned long long>(m+1, 0));
        vector<double> curr(m+1, 0), prev(m+1, 0);
        // for(int i = 0; i <= n; i++) curr[0] = 1;
        prev[0] = curr[0] = 1;
        // for(int j = 1; j <= m; j++) dp[0][j] = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i-1] == t[j-1]){
                    curr[j] = prev[j-1] + prev[j];
                }
                else{
                    curr[j] = prev[j];
                    }
            }
            prev = curr;
        }

        return prev[m];
    }
};