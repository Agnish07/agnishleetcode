class Solution {
public:
    typedef long long ll;
    pair<ll, ll> fn(int i, int j, vector<vector<int>>& grid, vector<vector<pair<ll, ll>>> &dp){
        
        int n = grid.size();
        int m = grid[0].size();

        if(i == n-1 && j == m-1) return {grid[i][j], grid[i][j]};

        if(dp[i][j] != make_pair(LLONG_MAX, LLONG_MIN)){
            return dp[i][j];
        }


        ll maxv = LLONG_MIN;
        ll minv = LLONG_MAX;

        if(i+1 < n){
            auto[downmn, downmx] = fn(i+1, j, grid, dp);
            maxv = max({maxv, grid[i][j] * downmx, grid[i][j] * downmn});
            minv = min({minv, grid[i][j] * downmx, grid[i][j] * downmn});
        }

        if(j+1 < m){
            auto[rightmn, rightmx] = fn(i, j+1, grid, dp);
            maxv = max({maxv, grid[i][j] * rightmx, grid[i][j] * rightmn});
            minv = min({minv, grid[i][j] * rightmx, grid[i][j] * rightmn});
        }

        return dp[i][j] = {minv, maxv};

    }
    int maxProductPath(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<pair<ll, ll>>> dp(n, vector<pair<ll, ll>>(m, {LLONG_MAX, LLONG_MIN}));
        auto [minp, maxp] = fn(0,0,grid, dp);

        if(maxp < 0) return -1;
        return maxp % MOD;
    }
};