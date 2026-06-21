class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int i = 0;
        int ans = 0;
        while(i < costs.size() && costs[i] <= coins){
            ans++;
            coins = coins - costs[i];
            i++;
        }
        return ans;
    }
};