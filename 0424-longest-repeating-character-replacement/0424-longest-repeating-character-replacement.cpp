class Solution {
public:
    int characterReplacement(string s, int k) {
        int r = 0, l = 0, maxf = 0, maxlen = 0;
        vector<int> hash(26,0);

        while(r < s.size()){
            hash[s[r] - 'A']++;
            maxf = max(maxf, hash[s[r] - 'A']);

            if((r-l+1) - maxf > k){
                hash[s[l] - 'A']--;
                l++;
            }
            
            else{
                maxlen = max(maxlen, r-l+1);

            }
            r++;
        }
        return maxlen;
    }
};