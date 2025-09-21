class Solution {
public:
    int rob2(vector<int> &nums){
        int prev2 = 0;
        int prev = nums[0];

        for(int i = 1; i < nums.size(); i++){
            int take = nums[i];
            if(i > 1) take += prev2;

            int nottake = prev;

            int curr = max(take, nottake);
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 0) return 0;  
        if (n == 1) return nums[0];
        
        vector<int> first(nums.begin(), nums.begin() + (n-1));
        vector<int> last(nums.begin() + 1, nums.end());

        int f = rob2(first);
        int l = rob2(last);

        return max(f,l);
    }
};