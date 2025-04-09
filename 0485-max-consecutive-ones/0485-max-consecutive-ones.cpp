class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        int maxx = INT_MIN;

        for(int i = 0; i < n; i++){
            if(nums[i] == 1){
                cnt++;
            }
            else{
                cnt = 0;
            }
            maxx = max(cnt,maxx);
        }
        return maxx;
    }
};