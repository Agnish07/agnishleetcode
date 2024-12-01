class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> ans(n);
        
        int maxcandies = *max_element(candies.begin(), candies.end());


        for(int i = 0; i < n; i++){
            ans[i] = maxcandies - candies[i] <= extraCandies;
        }

        return ans;
    }
};