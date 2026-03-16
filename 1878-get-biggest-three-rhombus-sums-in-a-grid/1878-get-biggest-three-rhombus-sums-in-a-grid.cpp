class Solution {
public:
    void addToSet(int n, set<int>& st) {
        st.insert(n);
        if (st.size() > 3)
            st.erase(st.begin());
    }

    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> d1(n, vector<int>(m, 0));
        vector<vector<int>> d2(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                d1[i][j] = grid[i][j];
                if (i - 1 >= 0 && j - 1 >= 0) {
                    d1[i][j] += d1[i - 1][j - 1];
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = m - 1; j >= 0; j--) {
                d2[i][j] = grid[i][j];
                if (i - 1 >= 0 && j + 1 < m) {
                    d2[i][j] += d2[i - 1][j + 1];
                }
            }
        }

        set<int> st;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                addToSet(grid[r][c], st);
                // sum += grid[r-1][c]+grid[r+1][c]+grid[r][c-1]+grid[r][c+1];
                // addToSet(sum, st);
                for (int s = 1;
                     r - s >= 0 && r + s < n && c - s >= 0 && c + s < m; s++) {
                    int sum = 0;

                    for(int k = 0; k <= s-1; k++){
                        sum += grid[r-s+k][c+k] + grid[r+k][c+s-k]
                               + grid[r+s-k][c-k] + grid[r-k][c-s+k];
                    }

                    // int top_r = r - s, top_c = c;
                    // int right_r = r, right_c = c + s;
                    // int bottom_r = r + s, bottom_c = c;
                    // int left_r = r, left_c = c - s;

                    // // top -> right
                    // sum += d1[right_r][right_c];
                    // if (top_r > 0 && top_c > 0)
                    //     sum -= d1[top_r - 1][top_c - 1];

                    // // right -> bottom
                    // sum += d2[bottom_r][bottom_c];
                    // if (right_r > 0 && right_c + 1 < m)
                    //     sum -= d2[right_r - 1][right_c + 1];

                    // // bottom -> left
                    // sum += d1[bottom_r][bottom_c];
                    // if (left_r > 0 && left_c > 0)
                    //     sum -= d1[left_r - 1][left_c - 1];

                    // // left -> top
                    // sum += d2[top_r][top_c];
                    // if (left_r > 0 && left_c + 1 < m)
                    //     sum -= d2[left_r - 1][left_c + 1];

                    // // remove duplicated corners
                    // sum -= grid[top_r][top_c];
                    // sum -= grid[right_r][right_c];
                    // sum -= grid[bottom_r][bottom_c];
                    // sum -= grid[left_r][left_c];

                    addToSet(sum, st);
                }
            }
        }

        vector<int> ans(st.begin(), st.end());
        reverse(ans.begin(), ans.end());
        return ans;
    }
};