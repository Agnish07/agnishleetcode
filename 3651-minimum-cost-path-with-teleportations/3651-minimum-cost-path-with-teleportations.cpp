class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        const int MAXV = 10000;
        const int INF = 1e9;

        vector<vector<vector<int>>> dp(
            k + 1, vector<vector<int>>(n, vector<int>(m, INF))
        );

        vector<int> bestpre(MAXV + 1, INF);

        for (int p = 0; p <= k; p++) {
            vector<int> bestcurr(MAXV + 1, INF);

            for (int i = n - 1; i >= 0; i--) {
                for (int j = m - 1; j >= 0; j--) {

                    if (i == n - 1 && j == m - 1) {
                        dp[p][i][j] = 0;
                    } else {
                        int ans = INF;

                        if (i + 1 < n)
                            ans = min(ans, grid[i + 1][j] + dp[p][i + 1][j]);

                        if (j + 1 < m)
                            ans = min(ans, grid[i][j + 1] + dp[p][i][j + 1]);

                        if (p > 0)
                            ans = min(ans, bestpre[grid[i][j]]);

                        dp[p][i][j] = ans;
                    }

                    bestcurr[grid[i][j]] =
                        min(bestcurr[grid[i][j]], dp[p][i][j]);
                }
            }

            bestpre[0] = bestcurr[0];
            for (int v = 1; v <= MAXV; v++)
                bestpre[v] = min(bestpre[v - 1], bestcurr[v]);
        }

        return dp[k][0][0];
    }
};
