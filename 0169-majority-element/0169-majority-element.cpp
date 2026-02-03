class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int i = 0;
        int cnt = 0;
        int n = nums.size();

        int el = nums[i];
        while(i < n){
            if(nums[i] == el) cnt++;
            else cnt--;

            if(cnt == 0) el = nums[i+1];
            i++;
        }
        // cnt = 0;
        // for(auto it : nums){
        //     if(it == el) cnt++;
        // }

        // if(cnt > n/2) return el;
        // return -1;
        return el;
    }
};