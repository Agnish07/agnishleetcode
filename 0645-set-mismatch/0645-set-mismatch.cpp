class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long n = nums.size();
        long long s1 = n*(n+1)/2;
        long long s2 = n*(n+1)*(2*n+1)/6;
        long long sum = 0;
        long long sum2 = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            sum2 += (long long)nums[i]*(long long)nums[i];
        }

        long long val1 = sum-s1; //x-y
        long long val2 = sum2-s2; 

        val2 = val2/val1; //x+y

        int x = (val1 + val2)/2;
        int y = val2-x;

        return {x,y};

    }
};