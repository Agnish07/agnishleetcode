class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]]++;
        }

        int maxi = 1;
        if(mpp.find(1) != mpp.end()){
            int ones = mpp[1];

            if(ones %2 != 1)ones--;
            maxi = max(maxi, ones);
        }

        for(auto& x : mpp){
            if(x.first == 1) continue;

            int currlen = 0;
            long curr = x.first;
            while(curr <= 1000000000LL && mpp.find((int)curr) != mpp.end() && mpp[(int)curr] >= 2){
                currlen += 2;
                curr *= curr;
            }

            if (curr <= 1000000000LL &&
                mpp.find((int)curr) != mpp.end() &&
                mpp[(int)curr] > 0) {
            currlen += 1;
                } 
            else {
                currlen -= 1;
            }

            maxi = max(maxi, currlen);
        }

        return maxi;
    }
};