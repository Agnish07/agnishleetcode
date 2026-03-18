class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        vector<vector<int>> gr = grid;
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;

        // for(int i = 0; i < n; i++){
        //     for(int j = 1; j < m; j++){
        //         gr[i][j] = gr[i][j] + gr[i][j-1];
        //     }
        // }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if(i > 0) gr[i][j] += gr[i-1][j];
                if(j > 0) gr[i][j] += gr[i][j-1];
                if(j > 0 && i > 0) gr[i][j] -= gr[i-1][j-1];

                if(gr[i][j] <= k) cnt++;
            }
        }

        return cnt;
    }
};