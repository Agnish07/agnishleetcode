class Solution {
public:
    int fn(vector<int> &nums, int t){
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(t+1, 0));

        if (nums[0] == 0) {
            dp[0][0] = 2;
        } else {
            dp[0][0] = 1;
            if (nums[0] <= t)
                dp[0][nums[0]] = 1;
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j <= t; j++){
                int nottake = dp[i-1][j];
                int take = 0;
                if(j >= nums[i]) take = dp[i-1][j-nums[i]];
                dp[i][j] = take + nottake;
            }
        }  

        return dp[n-1][t];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int totsum = 0;
        for(auto it : nums){
            totsum += it;
        }
        if((totsum-target)%2) return 0;
        if(totsum < abs(target)) return 0;
        else return fn(nums, (totsum-target)/2);
    }
};