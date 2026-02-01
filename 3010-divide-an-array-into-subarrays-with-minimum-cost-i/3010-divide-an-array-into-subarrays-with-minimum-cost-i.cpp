class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int x = nums[0];
        if(nums.size() == 3) return nums[0]+nums[1]+nums[2];
        sort(nums.begin(), nums.end());
        int y = 0;
        if(nums[0] == x) y = nums[1] + nums[2];
        else if(nums[1] == x) y = nums[0] + nums[2];
        else y = nums[0]+nums[1];
        return x+y;
    }
};