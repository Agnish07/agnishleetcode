class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int n = nums.size();

        // for(int j = 0; j < n; j++){
        //     if(nums[j] == 0){
        //         i = j;
        //         break;
        //     }
        // }

        // if(i == 0){
        //     nums = nums;
        // }

        for(int j = 0; j < nums.size();j++){
            if(nums[j] != 0){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++; 
            }
        }
    }
};