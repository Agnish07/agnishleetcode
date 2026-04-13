class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans = INT_MAX;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int d = -1;
            if(nums[i] == target){
                d = abs(i - start);
                ans = min(ans, d);
            }
        }

        return ans;
    }
};