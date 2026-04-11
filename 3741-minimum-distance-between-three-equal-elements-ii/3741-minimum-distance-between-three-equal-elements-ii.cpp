class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        unordered_map<int, vector<int>> mpp(n);

        for(int i = 0; i < n; i++){
            mpp[nums[i]].push_back(i);

            if(mpp[nums[i]].size() >= 3){
                vector<int> &vec = mpp[nums[i]];
                int s = mpp[nums[i]].size();

                int k = vec[s-3];

                ans = min(ans, 2*(i-k));

            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};