class Solution {
    public int majorityElement(int[] nums) {
        int n = nums.length;

        int maxc = 0;
        int maxn = -1;
        for(int i =0; i < n; i++){
        int count = 0;
            for(int j = 0; j < n; j++){
                if(nums[i] == nums[j]){
                    count++;
                }
                if(count > maxc){
                    maxc = count;
                    maxn = i;
                }
            }
        }
        if(maxc > n/2){
        return nums[maxn];
            }
            return 0;
    }
}