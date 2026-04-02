class Solution {
public:
    int solve(vector<vector<int>> &coins, int i, int j, int neu, vector<vector<vector<int>>> &dp){
        int n = coins.size();
        int m = coins[0].size();

        if(i == n-1 && j == m-1){
            if(coins[i][j] < 0 && neu > 0) return 0;
            else return coins[i][j];
        }


        if(i == n || j == m) return INT_MIN;

        if(dp[i][j][neu] != INT_MIN) return dp[i][j][neu];
        int take = coins[i][j] + max(solve(coins, i+1, j, neu, dp), solve(coins,i,j+1,neu, dp));


        int nottake = INT_MIN;
        if(coins[i][j] < 0 && neu > 0){
            int right = solve(coins, i, j+1, neu-1, dp);
            int down = solve(coins, i+1, j, neu-1, dp);

            nottake = max(right, down);
        }

        return dp[i][j][neu] = max(take, nottake);
        
    }
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, INT_MIN)));
        return solve(coins, 0, 0, 2, dp);
    }
};