class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                int r = (i+nums[i])%n;
                result[i] = nums[r];
            }
            else if (nums[i] < 0){
                int l = ((i + nums[i]) % n + n) % n;
                result[i] = nums[l];
            }
            else{
                result[i] = nums[i];
            }
        }
        return result;
    }
};