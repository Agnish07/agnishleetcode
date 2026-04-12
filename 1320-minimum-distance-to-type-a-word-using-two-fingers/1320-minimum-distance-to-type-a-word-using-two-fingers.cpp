class Solution {
public:
    int dp[301][27][27];
    pair<int, int> getCoord(int pos){
        return {pos/6, pos%6};
    }

    int getdist(int p1, int p2){
        auto [x1, y1] = getCoord(p1);
        auto [x2, y2] = getCoord(p2);

        return abs(x1-x2) + abs(y1-y2);
    }

    int solve(string word, int i, int f1, int f2){
        if(i >= word.size()) return 0;
        
        if(dp[i][f1][f2] != -1) return dp[i][f1][f2];

        int cur = word[i] - 'A';

        if(f1 == 26 && f2 == 26){
            return dp[i][f1][f2] = solve(word, i+1, cur, f2);
        }

        if(f2 == 26){
            int mf2 = solve(word, i+1, f1, cur);
            int mf1 = getdist(f1, cur) + solve(word, i+1, cur, f2);
            return dp[i][f1][f2] = min(mf1, mf2);
        }

        int mf1 = getdist(f1, cur) + solve(word, i+1, cur, f2);
        int mf2 = getdist(f2, cur) + solve(word, i+1, f1, cur);
        return dp[i][f1][f2] = min(mf1, mf2);
    }
    int minimumDistance(string word) {
        memset(dp, -1, sizeof(dp));
        return solve(word, 0, 26, 26);
    }
};