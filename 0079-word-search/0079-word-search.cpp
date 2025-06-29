class Solution {
public:

    vector<vector<int>> dir{{1,0},{-1,0},{0,1},{0,-1}};

    bool find(vector<vector<char>>& board, int i, int j, int ind, string &word){
        if(ind == word.length()) return true;

        int m = board.size();
        int n = board[0].size();

        if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '$') 
            return false;

        if(board[i][j] != word[ind]) return false;

        char temp = board[i][j];
        board[i][j] = '$';

        for(auto &d : dir){
            if(find(board, i+d[0], j+d[1], ind+1, word)) return true;
        }

        board[i][j] = temp;

        return false; 
            }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int i = 0; i < m;i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0] && find(board,i,j,0,word)){
                    return true;
                }
            }
        }
        return false;
    }
};