class Solution {
public:
    // int f(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp){
    //     int n = matrix.size();
    //     int m = matrix[0].size();

    //     if(j < 0 || j > m-1) return 1e9;
    //     if(i == 0) return matrix[i][j];
        
    //     if(dp[i][j] != -1) return dp[i][j];

    //     int u = matrix[i][j] + f(i-1, j, matrix, dp);
    //     int ld = matrix[i][j] + f(i-1, j-1, matrix, dp);
    //     int rd = matrix[i][j] + f(i-1, j+1, matrix, dp);

    //     return dp[i][j] = min(u, min(ld,rd));
    // }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        for(int j = 0; j < m; j++) dp[0][j] = matrix[0][j];

        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                int ld = INT_MAX;
                int rd = INT_MAX;
                int u = matrix[i][j] + dp[i-1][j];
                if(j-1 >= 0) ld = matrix[i][j] + dp[i-1][j-1];
                if(j+1 < m) rd = matrix[i][j] + dp[i-1][j+1];

                dp[i][j] = min(u, min(ld,rd));
            }
        }

        int ans = INT_MAX;
        for(int j = m-1; j >= 0; j--){
            ans = min(ans, dp[n-1][j]);
        }
        return ans;
    }
};