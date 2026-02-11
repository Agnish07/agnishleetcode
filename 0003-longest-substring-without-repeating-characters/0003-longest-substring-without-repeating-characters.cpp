class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        int maxi = 0;
        unordered_map<char, int> mpp;

        while(j < s.size() && i <= j){
            if(mpp.find(s[j]) == mpp.end()){
                mpp[s[j]] = j;
                maxi = max(maxi, j-i+1);
                j++;
                continue;
            }
            else{
            i = max(i, mpp[s[j]]+1);
            mpp[s[j]] = j;
            maxi = max(maxi, j - i + 1);
            j++;
            }

        }

        return maxi;
    }
};