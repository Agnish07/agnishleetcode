class Solution {
public:
    void backtrack(int n, int open, int close, string brackets, vector<string> &result){
        if(brackets.length() == 2*n && open == close){
            result.push_back(brackets);
            return;
        }
        if(open < n){
            backtrack(n,open+1,close,brackets+"(",result);
        }
        if(close < open){
            backtrack(n,open,close+1,brackets+")",result);
        }
    }


    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(n,0,0,"",result);
        return result;
    }
};