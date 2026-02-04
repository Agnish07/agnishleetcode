class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        vector<long long> istart(n, INT_MAX);
        vector<long long> iend(n, INT_MIN);
        long long ans = LLONG_MIN;

        for(int i = 0; i < n; i++){
            iend[i] = nums[i];
            if(i > 0 && nums[i] > nums[i-1]){
                iend[i] = max((long long)nums[i] + nums[i-1], iend[i-1]+iend[i]);
            }
        }

        for(int i = n-1; i >= 0; i--){
            istart[i] = nums[i];
            if(i < n-1 && nums[i] < nums[i+1]){
                istart[i] = max((long long)nums[i] + nums[i+1], istart[i+1]+nums[i]);
            }
        }

        for(int i = 1; i < n-1; i++){
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1]){
                int j = i;
                long long sum = 0;
                while(j < n-1 && nums[j] > nums[j+1]){
                    sum += nums[j];
                    j++;
                }

                if(j < n-1 && nums[j] < nums[j+1]){
                    ans = max(ans,iend[i]-nums[i]+sum+istart[j]);
                }
                i = j;
            }
        }

        return ans;
    }
};