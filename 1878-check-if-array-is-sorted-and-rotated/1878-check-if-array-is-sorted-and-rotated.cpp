class Solution {
 public:
  bool check(vector<int>& nums) {
    const int n = nums.size();
    int count = 0;

    if(n==1){
        return true;
    }

    for(int i = 0; i < n; i++){
        if(nums[(i+1)%n] < nums[i]){
            count++;
        }
        if(count > 1){
            return false;
        }
    }

    return true;

  }
};