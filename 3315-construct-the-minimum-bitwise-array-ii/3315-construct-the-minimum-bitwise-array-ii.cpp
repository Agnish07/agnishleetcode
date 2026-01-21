class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 2) ans[i] = -1;
            else{
                int n = nums[i];
                int mask = ~(((n+1)&~n)>>1);
                ans[i] = n & mask;
            }
        }
        return ans;
    }
};