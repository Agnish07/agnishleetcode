class Solution {
public:
    int fn(vector<int>& nums, int k){
         int l = 0, r = 0, cnt = 0;
        unordered_map<int,int> mpp;
        int n = nums.size();

        while(r < n){
            mpp[nums[r]]++;

            while(mpp.size() > k){
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0) mpp.erase(nums[l]);
                l++;
            }
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return fn(nums,k) - fn(nums,k-1);

        
    }

};