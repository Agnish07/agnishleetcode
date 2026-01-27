class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<long>> dp(n + 1, vector<long>(2, 0));

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy < 2; buy++) {
                long profit;
                if (buy) {
                    long buyStock = -prices[ind] + dp[ind + 1][0];
                    long skip = dp[ind + 1][1];
                    profit = max(buyStock, skip);
                } else {
                    long sellStock = prices[ind] + dp[ind + 1][1];
                    long skip = dp[ind + 1][0];
                    profit = max(sellStock, skip);
                }
                dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
    }
};
