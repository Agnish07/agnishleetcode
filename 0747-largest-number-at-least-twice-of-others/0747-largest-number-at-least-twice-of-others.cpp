class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int ans = -1;

        int k = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[k] < nums[i]){
                k = i;
            }
        }

        for(int i = 0; i < nums.size(); i++){
            if(k != i && nums[k] < nums[i]*2){
                return -1;
            }
        }
        return k;
    }
};