class Solution {
public:
    bool f(int n, int k, vector<int>& nums, vector<vector<int>> &dp){
        if(k == 0) return true;
        if(n == 0) return (nums[0] == k);
        if(dp[n][k] != -1) return dp[n][k];
        bool nottake = f(n-1, k, nums, dp);
        bool take = false;
        if(k >= nums[n]) take = f(n-1, k - nums[n], nums, dp);

        return dp[n][k] = take or nottake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        for(int i = 0; i < nums.size(); i++){
            s += nums[i];
        }
        if (s % 2 != 0) return false;

        int k = s/2;
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        return f(n-1, k, nums, dp);
    }
};