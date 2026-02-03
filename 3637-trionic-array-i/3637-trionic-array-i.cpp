class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int i = 1;
        int n = nums.size();
        while(i < n && nums[i] > nums[i-1]) i++;
        int inc1 = i-1;
        while(i < n && nums[i] < nums[i-1]) i++;
        int dec = i-1;
        while(i < n && nums[i] > nums[i-1])i++;
        int inc2 = i-1;
        return (inc1 != 0 && dec != inc1 && (inc2 != dec && inc2 == n-1));
    }
};