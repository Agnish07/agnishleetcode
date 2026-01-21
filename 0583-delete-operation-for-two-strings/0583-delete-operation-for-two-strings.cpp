class Solution {
public:
    int lcs(string &w1, string &w2){
        int n = w1.size();
        int m = w2.size();
        vector<int> prev(m+1, 0), curr(m+1, 0);

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(w1[i-1] == w2[j-1]) curr[j] = prev[j-1] + 1;
                else{
                    curr[j] = max(prev[j], curr[j-1]);
                }
            }
            prev = curr;
        }

        return prev[m];

    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        int ls = lcs(word1, word2);

        int x = max(m,n);

        return (m+n-(2*ls));
    }
};