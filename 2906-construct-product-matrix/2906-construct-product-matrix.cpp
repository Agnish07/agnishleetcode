class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int MOD = 12345;

        vector<vector<int>> ans(n, vector<int>(m,1));
        long long pre = 1;
        long long suf = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans[i][j] = pre;
                pre = (pre * grid[i][j] * 1LL) % MOD;
            }
        }

        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                ans[i][j] = (suf*ans[i][j]) % MOD;
                suf = (suf * grid[i][j] * 1LL) % MOD;
            }
        }

        return ans;
    }
};