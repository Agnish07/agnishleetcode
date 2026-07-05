class Solution {
public:
    int n;
    int MOD = 1e9+7;
    int getint(char ch){
    return (ch >= '0' && ch <= '9') ? ch - '0' : 0;
    }

    bool isVal(int i, int j, vector<string> &board){
        if(i >= 0 && i < n && j >= 0 && j < n && board[i][j] != 'X') return true;
        return false;
    }

    

    pair<int, int> solve(int i,int j, vector<string> &board, vector<vector<pair<int,int>>> &dp ){
        if (board[i][j] == 'E')
            return dp[i][j] = {0,1};

        if (board[i][j] == 'X')
            return dp[i][j] = {0,0};        

        if(dp[i][j].first != -1 && dp[i][j].second != -1) return dp[i][j];

        int upscore = 0, uppath = 0, leftscore = 0, leftpath = 0, diagscore = 0, diagpath = 0;

        char ch = board[i][j];

        if(isVal(i-1, j, board)){
            auto [scores, paths] = solve(i-1, j, board, dp);
            upscore = scores;
            uppath = paths;

            if(uppath > 0){
                upscore += getint(ch);
            }
        }

        if(isVal(i, j-1, board)){
            auto [scores, paths] = solve(i, j-1, board, dp);
            leftscore = scores;
            leftpath = paths;

            if(leftpath > 0){
                leftscore += getint(ch);
            }
        }

        if(isVal(i-1, j-1, board)){
            auto [scores, paths] = solve(i-1, j-1, board, dp);
            diagscore = scores;
            diagpath = paths;

            if(diagpath > 0){
                diagscore += getint(ch);
            }
        }

        if (uppath == 0 && leftpath == 0 && diagpath == 0)
        return dp[i][j] = {0, 0};

        int bestscore, bestpath;


        if (upscore == leftscore && leftscore == diagscore) {
            bestscore = upscore;
            bestpath = uppath + leftpath + diagpath;
        } else if (upscore == leftscore) {
            bestscore = upscore;
            bestpath = uppath + leftpath;

            if (diagscore > bestscore || (diagscore == bestscore && diagpath > bestpath)) {
                bestscore = diagscore;
                bestpath = diagpath;
            }
        } else if (leftscore == diagscore) {
            bestscore = leftscore;
            bestpath = leftpath + diagpath;

            if (upscore > bestscore || (upscore == bestscore && uppath > bestpath)) {
                bestscore = upscore;
                bestpath = uppath;
            }
        } else {
            bestscore = upscore;
            bestpath = uppath;

            if (leftscore > bestscore || (leftscore == bestscore && leftpath > bestpath)) {
                bestscore = leftscore;
                bestpath = leftpath;
            }

            if (diagscore > bestscore || (diagscore == bestscore && diagpath > bestpath)) {
                bestscore = diagscore;
                bestpath = diagpath;
            }
        }

        return dp[i][j] = {bestscore, bestpath % MOD};
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();
        vector<vector<pair<int, int>>> dp(n, vector<pair<int,int>> (n, {-1, -1}));
        pair<int, int> ans = solve(n-1, n-1, board, dp);
        return {ans.first, ans.second};
    }
};