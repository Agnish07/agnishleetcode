class Solution {
public:
    int minimumCost(vector<int>& nums) {
        // int x = nums[0];
        // if(nums.size() == 3) return nums[0]+nums[1]+nums[2];
        // sort(nums.begin()+1, nums.end());
        // int y = nums[1] + nums[2];
        // return x+y;
        int cost = nums[0];
        int min1 = INT_MAX;
        int min2 = INT_MAX;

        for(int i = 1 ; i < nums.size();i++){
            int cur = nums[i];
            if(cur < min1){
                min2 = min1;
                min1 = cur;
            }else if(min2 > cur){
                min2 = cur;
            }
        }
        cost += min1 + min2;
        return cost;
    }
};