class Solution {
public:
    // int fn(string &w1, string &w2, int i, int j, vector<vector<int>> &dp){
    //     if(i < 0) return j+1;
    //     if(j < 0) return i+1;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     if(w1[i] == w2[j]) return dp[i][j] = fn(w1, w2, i-1, j-1, dp);
    //     return dp[i][j] = 1 + 
    //     min(fn(w1,w2,i-1,j,dp),
    //     min(fn(w1,w2,i-1,j-1,dp),
    //     fn(w1,w2,i,j-1,dp)));
    // }
    int minDistance(string w1, string w2) {
        int n = w1.size();
        int m = w2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int j = 0; j <= m; j++) dp[0][j] = j;
        for(int i = 0; i <= n; i++) dp[i][0] = i;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(w1[i-1] == w2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = 1 + min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
            }
        }
        
        return dp[n][m];
    }
};