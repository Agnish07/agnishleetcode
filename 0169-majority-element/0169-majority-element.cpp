class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int el = 0;
        int cnt = 0;

        for(int i = 0; i < n; i++){
            if(cnt == 0){
                cnt = 1;
                el = nums[i];
            }
            else if(nums[i] == el){
                cnt++;
            }
            else cnt--;
        }

        int cnt1 = 0;
        for(int i = 0; i < n; i++){
            if(el == nums[i]){
                cnt1++;
            }
        }
        if(cnt1 > (n/2)){
            return el;
        }
        return -1;
    }
};