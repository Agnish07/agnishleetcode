class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        int l = 0, r = k-1;
        int ans;
        int res = INT_MAX;

        while(r < n){
            ans = nums[r] - nums[l];
            res = min(res,ans);
            l++;
            r++;
        }
        return res;
    }
};