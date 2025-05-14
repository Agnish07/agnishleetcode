class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int lb = -1;
        int ub = n;

        while(low <= high){
            int mid = low + ((high - low)/2);

            if(nums[mid] >= target){
                lb = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        low = 0;
        high = n-1;

        while(low <= high){
            int mid = low + ((high - low)/2);

            if(nums[mid] <= target){
                ub = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        if(ub == n || nums[ub] != target || nums[lb] != target){
            ub = -1;
            lb = -1;
        }
        return {lb, ub};
    }
};