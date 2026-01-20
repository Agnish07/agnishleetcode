class Solution {
public:
    int lcs(string s){
        string s1 = s;
        reverse(s.begin(), s.end());
        string s2 = s;
        int n = s.size();
        vector<int> prev(n+1, 0), curr(n+1, 0);

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(s1[i-1] == s2[j-1]) {
                    curr[j] = prev[j-1] + 1;
                    }
                else{
                    curr[j] = max(prev[j], curr[j-1]);
                }
            }
            prev = curr;
        }
        return prev[n];
    }

    int minInsertions(string s) {
        int n = s.size();
        return n - lcs(s);
    }
};