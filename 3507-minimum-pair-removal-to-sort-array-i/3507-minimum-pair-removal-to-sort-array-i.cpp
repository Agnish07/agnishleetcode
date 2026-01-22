class Solution {
public:
    void fn(vector<int> &nums, int& x){
        bool fl = false;
        for(int i = 1; i < nums.size();i++){
            if(nums[i] < nums[i-1]) fl = true;
        }

        pair<int, int> ind(0,0);
        if(fl == false) return;
        else{
            int mini = INT_MAX;
            for(int i = 1; i < nums.size();i++){
                int sum = nums[i-1] + nums[i];

                if (sum < mini){
                    ind = {i-1, i};
                    mini = sum;
                }
            }
            int newe = nums[ind.first] + nums[ind.second];
            nums.erase(nums.begin() + ind.second);
            nums.erase(nums.begin() + ind.first);
            nums.insert(nums.begin()+ind.first, newe);
            x++;
            fn(nums, x);
        }
        return;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int x = 0;
        fn(nums, x);
        return x;
    }
};