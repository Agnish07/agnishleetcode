class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int MOD = 1e9+7;
        for(auto& q : queries){
            int l = q[0];
            int r = q[1];
            int k = q[2];
            int v = q[3];

            while(l <= r){
                nums[l] = (1LL * nums[l]*v)%MOD;
                l += k;
            }
        }

        int ans = 0;
        for(auto n : nums){
            ans ^= n;
        }

        return ans;
    }
};