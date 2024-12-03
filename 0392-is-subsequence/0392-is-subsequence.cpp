class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.length();
        int n = t.length();

        int i = 0;
        int j = 0;

        for(; i < m && j < n; j++){
            if(s[i] == t[j]){
                i++;
            }
        }

            return i == m;
    }
};