class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<long long> prev(amount+1, 0), curr(amount+1, 0);

        for(int t = 0; t <= amount; t++){
            if(t % coins[0] == 0) prev[t] = 1;
        }

        for(int ind = 1; ind < n; ind++){
            fill(curr.begin(), curr.end(), 0);

            for(int t = 0; t <= amount; t++){
                curr[t] += prev[t];
                int take = 0;
                if(coins[ind] <= t) take = curr[t - coins[ind]];
                curr[t] += take;
            }
            prev = curr;
        }

        return prev[amount];
    }
};
