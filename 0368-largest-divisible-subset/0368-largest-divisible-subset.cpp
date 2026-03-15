class Solution {
public:
    // void fn(vector<int> &nums, int ind, int prev,vector<int> &curr, vector<int> &ans, int n){
    //     if(ind == n){
    //         if (curr.size() > ans.size()){
    //             ans = curr;
    //         }
    //         return;
    //     }

    //     if(prev == -1 || nums[ind] % nums[prev] == 0){
    //             curr.push_back(nums[ind]);
    //             fn(nums, ind+1, ind, curr, ans, n);
    //             curr.pop_back();
    //     }

    //     fn(nums, ind+1, prev, curr, ans, n);
    // }


    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> hash(n);
        int lastind = 0;

        for(int i = 0; i < n; i++){
            hash[i] = i;
        }

        int maxi = 1;
        for(int i = 1; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                if(nums[i]%nums[prev] == 0 && 1+dp[prev] > dp[i]){
                    dp[i] = 1+dp[prev];
                    hash[i] = prev;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                lastind = i;
            }
        }

        vector<int> temp;
        while(hash[lastind] != lastind){
            temp.push_back(nums[lastind]);
            lastind = hash[lastind];
        }
        temp.push_back(nums[lastind]);
        reverse(temp.begin(), temp.end());
        return temp;
    }
};