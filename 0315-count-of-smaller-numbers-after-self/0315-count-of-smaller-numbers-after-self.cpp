class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans;
        vector<int> sorted;

        for(int i = nums.size()-1 ; i >= 0 ; i--){
            int val = nums[i];
            auto it = lower_bound(sorted.begin(), sorted.end(), val);
            ans.push_back(it - sorted.begin());
            sorted.insert(it, val);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};