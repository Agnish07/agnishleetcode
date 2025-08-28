class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        map<int, int> mpp;
        for(int i : nums){
            mpp[i]++;
        }
        int a = 0;
        int b = 0;
        for(int i = 0; i < mpp.size(); i++){
            if(mpp[i] >= 2) a += mpp[i]/2;
        }
        b = nums.size()-a*2;
        return{a,b};
    }
};