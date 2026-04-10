class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mpp;
        int n = nums.size();

        // Store indices
        for(int i = 0; i < n; i++){
            mpp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        // Iterate over map
        for(auto &it : mpp){
            vector<int> &v = it.second;

            if(v.size() >= 3){
                for(int i = 0; i + 2 < v.size(); i++){
                    int val = abs(v[i] - v[i+1]) +
                              abs(v[i] - v[i+2]) +
                              abs(v[i+1] - v[i+2]);

                    ans = min(ans, val);
                }
            }
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};