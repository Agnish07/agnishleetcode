class Solution {
public:
int search(vector<int>& nums, int target) {
int n = nums.size();
int low = 0;
int high = n-1;

    while(low <= high){
        int mid = low + ((high - low)/2);
        while(low < high && nums[low] == nums[mid] && nums[mid] == nums[high]){
            low = low + 1;
            high = high - 1;
        }

        if(nums[mid] == target) return true;
        
        if(nums[mid] >= nums[low]){
            if(nums[mid] >= target && nums[low] <= target){
                high = mid - 1;
            }  
            else{
                low = mid + 1;
            }
        }
        
        else{
            if(nums[mid] <= target && nums[high] >= target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    return false;
}

};
