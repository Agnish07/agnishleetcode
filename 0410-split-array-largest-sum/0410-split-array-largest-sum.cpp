class Solution {
public:
    int count(vector<int> &arr, int units){
        int painter = 1;
        int wall = 0;

        for(int i = 0; i < arr.size();i++){
            if(wall + arr[i] <= units){
                wall += arr[i];
            }
            else{
                painter += 1;
                wall = arr[i];
            }
        }
        return painter;
    }
    int splitArray(vector<int>& nums, int k) {
        // sort(nums.begin(),nums.end());
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = -1;
        if(k > nums.size()) return -1;
        while(low <= high){
            int mid = low + ((high - low)/2);

            if(count(nums, mid) > k){
                low = mid + 1;
            }
            else{
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};