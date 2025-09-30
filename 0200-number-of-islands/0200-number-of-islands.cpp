class Solution {
public:

    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>& grid){
        vis[row][col] = 1;

        queue<pair<int, int>> q;
        q.push({row, col});
        int n = grid.size();
        int m = grid[0].size();
        int drow[] = {0,1,0,-1};
        int dcol[] = {1,0,-1,0};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == '1'){
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
            }
            
        }
    }


    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    bfs(i, j, vis, grid);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};