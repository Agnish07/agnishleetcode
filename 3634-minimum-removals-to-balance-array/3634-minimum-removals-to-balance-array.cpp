class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        if(nums.size() <= 1) return 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = 1;;
        int maxi = 0;

        while(j < n){
            while((long long)nums[i]*k < (long long)nums[j]){
                i++;
            }
            maxi = max(maxi, j-i+1);
            j++;
        }

        return n-maxi;


    }
};