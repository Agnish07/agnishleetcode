class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        
        constexpr int kmax = 100;

        vector<int> ans;
        vector<int> count(kmax + 1);

        for(const int num : nums){
            count[num]++ ;
        }

        for(int i = 1; i < kmax; i++){
            count[i] += count[i-1];
        }

        for(const int num : nums){
            ans.push_back(num == 0 ? 0 : count[num-1]);
        }
        
        return ans;
    }
};