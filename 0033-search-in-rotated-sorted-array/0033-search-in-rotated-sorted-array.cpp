class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0 ; int right = nums.size() - 1;
        // if(nums[left] == target){
        //     return left;
        // }
        // else if (nums[right] == target){
        //     return right;
        // }

        while(left <= right){
            int mid = (left + right) / 2;

            if(target == nums[mid]){
                return mid;
            }

            if(nums[left] <= nums[mid]){
                if(target > nums[mid] || target < nums[left]){
                    left = mid + 1;
                }
            else{
                right = mid - 1;}
            }
            else{
                if(target < nums[mid] || target > nums[left]){
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }

        }
        return -1;
    }
};