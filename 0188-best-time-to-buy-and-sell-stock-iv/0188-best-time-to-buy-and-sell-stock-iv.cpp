class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int>(k+1,0)));
        // for(int i = 0; i < n;i++){
        //     for(int buy = 0; buy < 2; buy++){
        //         dp[i][buy][0] = 0;
        //     }
        // }
        // for(int buy = 0; buy < 2;buy++){
        //     for(int cap = 0; cap < 3; cap++){
        //         dp[n][buy][cap] = 0;
        //     }
        // }
        for(int ind = n-1; ind >= 0; ind--){
            for(int buy = 0; buy < 2; buy++){
                for(int cap = 1; cap <= k; cap++){
                    if(buy == 1){
                        dp[ind][buy][cap] = max(-prices[ind]+dp[ind+1][0][cap],
                                        dp[ind+1][1][cap]);
                    }
                    else{
                        dp[ind][buy][cap] = max(prices[ind] + dp[ind+1][1][cap-1],
                                        dp[ind+1][0][cap]);
                    }
                }
            }
        }

        return dp[0][1][k];   
    }
};