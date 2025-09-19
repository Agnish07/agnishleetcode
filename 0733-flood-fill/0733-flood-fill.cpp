class Solution {
public:
    void dfs(vector<vector<int>> &img, int r, int c, int nc, int ini, vector<vector<int>> &ans){
        ans[r][c] = nc;
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,-1,0,1};
        int n = img.size();
        int m = img[0].size();

        for(int i = 0; i < 4; i++){
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && img[nrow][ncol] == ini && ans[nrow][ncol] != nc){
                dfs(img, nrow, ncol, nc, ini, ans);
            }

        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ini = image[sr][sc];
        vector<vector<int>> ans = image;
        dfs(image, sr, sc, color, ini, ans);

        return ans;
    }
};