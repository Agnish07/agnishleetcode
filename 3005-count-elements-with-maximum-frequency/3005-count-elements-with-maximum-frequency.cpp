class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mpp;

        for(int i = 0; i < nums.size();i++){
            mpp[nums[i]]++;
        }


        int ans = 0;
        int maxf = INT_MIN;

        for(auto& [key, count] : mpp){
            maxf = max(maxf, count);
        }
        
        for(auto& [key, count] : mpp){
            if(count == maxf) ans += count;
        }

        return ans;

    }
};