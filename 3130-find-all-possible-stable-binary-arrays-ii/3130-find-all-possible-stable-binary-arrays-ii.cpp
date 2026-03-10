class Solution {
public:
    int MOD = 1e9 + 7;

    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<int>>> dp(zero+1, vector<vector<int>>(one+1, vector<int>(2,0)));

        for(int i = 0; i <= min(zero,limit); i++){
            dp[i][0][0] = 1;
        }

        for(int i = 0; i <= min(one,limit); i++){
            dp[0][i][1] = 1;
        }

        for(int z = 0; z <= zero; z++){
            for(int o = 0; o <= one; o++){
                if(o == 0 || z == 0) continue;

                   dp[z][o][0] = (dp[z-1][o][0] + dp[z-1][o][1]) % MOD;

                    if(z-1 >= limit){
                        dp[z][o][0] = (dp[z][o][0] - dp[z-1-limit][o][1] + MOD) % MOD;
                    }

                    dp[z][o][1] = (dp[z][o-1][0] + dp[z][o-1][1]) % MOD;

                    if(o-1 >= limit) {
                         dp[z][o][1] = (dp[z][o][1] - dp[z][o-1-limit][0] + MOD) % MOD;
                    }
            }
        }

        int a = dp[zero][one][0];
        int b = dp[zero][one][1];
        return (a+b) % MOD;
    }
};