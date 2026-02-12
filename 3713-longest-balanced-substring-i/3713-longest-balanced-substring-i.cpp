class Solution {
public:
    int longestBalanced(string s) {
        int ans = INT_MIN;
        int n = s.size();
        for(int i = 0; i < n; i++){
            unordered_map<char, int> mpp;
            for(int j = i ; j < n; j++){
                mpp[s[j]]++;
                bool flag = true;
                for(auto it : mpp){
                    if(it.second != mpp[s[j]]) flag = false;
                }
                    if(flag == true) ans = max(ans, j-i+1);
            }
        }
        return ans;
    }
};