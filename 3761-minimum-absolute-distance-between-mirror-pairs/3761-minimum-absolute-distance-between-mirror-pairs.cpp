class Solution {
public:
    long long reverse(int x){
        long long n = 0;
        while(x > 0){
            n = n*10 + (x%10);
            x = x/10;
        }

        return n;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<long long, int> mpp;
        int ans = INT_MAX;

        for(int i = 0; i < nums.size(); i++){

            int rev = reverse(nums[i]);
            if(mpp.find(nums[i]) != mpp.end()) ans = min(ans, (i-mpp[nums[i]]));
            mpp[rev] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};