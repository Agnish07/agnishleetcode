class Solution {
public:
    int MOD = 1e9 + 7;
    int solve(int z, int o, int l, int last, vector<vector<vector<int>>> &dp){
        if(z == 0 && o == 0) return 1;
        int res = 0;
        if(dp[z][o][last] != -1) return dp[z][o][last];
        if(last == 1){
            for(int i = 1; i <= min(z, l); i++){
                res += solve(z-i,o,l,0,dp);
            }
        }
        else{
            for(int i = 1; i <= min(o, l); i++){
                res += solve(z,o-i,l,1,dp);
            }
        }

        return dp[z][o][last] = res;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        int res = 0;
        vector<vector<vector<int>>> dp(zero+1, vector<vector<int>>(one+1, vector<int>(2, -1)));

        dp[0][0][1] = 1;
        dp[0][0][0] = 1;

        for(int z = 0; z <= zero; z++){
            for(int o = 0; o <= one; o++){
                if(o == 0 && z == 0) continue;
                int result = 0;
                // if(dp[z][o][last] != -1) return dp[z][o][last];

                    for(int i = 1; i <= min(z, limit); i++){
                        result = (result + dp[z-i][o][0]) % MOD;
                    }
                    dp[z][o][1] = result;

                    result = 0;
                    for(int i = 1; i <= min(o, limit); i++){
                        result = (result + dp[z][o-i][1]) % MOD;
                    }
                    dp[z][o][0] = result;
            }
        }

        int a = dp[zero][one][0];
        int b = dp[zero][one][1];
        return (a+b) % MOD;
    }
};