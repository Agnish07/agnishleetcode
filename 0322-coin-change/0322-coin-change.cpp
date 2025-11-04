class Solution {
public:

    int f(int i, vector<int>& a, int t, vector<vector<int>> &dp){

        if(i == 0){
            if(t % a[i] == 0) return t/a[i];
            else return 1e9;
        }
        if(dp[i][t] != -1) return dp[i][t];
        int nottake = 0 + f(i-1, a, t, dp);
        int take = INT_MAX;

        if(a[i] <= t) take = 1+ f(i, a, t - a[i], dp);

        return dp[i][t] = min(take, nottake);

    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = f(n - 1, coins, amount, dp);
        if (ans >= 1e9) return -1;
        return ans;
    }
};