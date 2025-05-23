class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = INT_MAX;

        while(low <= high){
            int mid = low + ((high - low)/2);

            while(low < high && nums[low] == nums[mid] && nums[mid] == nums[high]){
                low++;
                high--;
            }
            
            // if(nums[low] < nums[high]){
            //     return nums[low];
            // }

            if(nums[low] <= nums[mid]){
                ans = min(nums[low],ans);
                low = mid + 1;
            }
            else{
                ans = min(nums[mid],ans);
                high = mid - 1;
            }
        }
        return ans;
    }
};