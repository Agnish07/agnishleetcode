class Solution {
public:
    bool check(string s1, string s2){
        if(s2.size() != s1.size() + 1) return false;
        int i = 0;
        int j = 0;
        while(i < s1.size() && j < s2.size()){
            if(s1[i] == s2[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
         return i == s1.size();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n, 1);
        int maxi = 1;
        sort(words.begin(), words.end(), [](string &a, string &b){
    return a.size() < b.size();
});

        for(int i = 1; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                if(check(words[prev], words[i]) && 1+dp[prev] > dp[i]){
                    dp[i] = 1+dp[prev];
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
            }   
        }
            return maxi;  
    }
};