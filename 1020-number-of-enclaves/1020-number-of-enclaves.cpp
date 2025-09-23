class Solution {
public:
    void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis){
        vis[row][col] = 1;

        int n = grid.size();
        int m = grid[0].size();

        int drow[] = {0,1,0,-1};
        int dcol[] = {1,0,-1,0};

        for(int i = 0; i < 4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                dfs(nrow,ncol, grid, vis);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0));

        for(int i = 0; i < n; i++){
            if(!vis[i][0] && grid[i][0]){
                dfs(i,0,grid, vis);
            }

            if(!vis[i][m-1] && grid[i][m-1]){
                dfs(i,m-1,grid, vis);
            }
        }

        for(int j = 0; j < m; j++){
            if(!vis[0][j] && grid[0][j]){
                dfs(0,j,grid, vis);
            }

            if(!vis[n-1][j] && grid[n-1][j]){
                dfs(n-1,j,grid, vis);
            }
        }

        int cnt = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(vis[i][j] == 0 && grid[i][j] == 1) cnt++;
            }
        }

    return cnt;

    }
};