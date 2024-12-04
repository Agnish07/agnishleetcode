class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;

            for(int i = 0; i < k; i++){
                sum += nums[i]; 
        }

        double maxavg = static_cast<double>(sum)/k;

        for(int i = k; i < n; i++){
            sum = sum - nums[i-k] + nums[i];
            maxavg = max(maxavg, static_cast<double>(sum)/k);
        }
        return maxavg;
    }
};