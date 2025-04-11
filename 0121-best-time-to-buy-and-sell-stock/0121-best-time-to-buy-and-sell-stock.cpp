class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;
        int maxprofit = 0;
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < mini){
                mini = prices[i];
            }

            int profit = prices[i] - mini;
            maxprofit = max(maxprofit, profit);
            if(profit < 0){
                profit = 0;
            }
        }
        return maxprofit;
    }
};