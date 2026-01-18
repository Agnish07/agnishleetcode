class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> row(m, vector<int>(n + 1, 0));
        vector<vector<int>> col(m + 1, vector<int>(n, 0));
        vector<vector<int>> diag(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> anti(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                row[i][j + 1] = row[i][j] + grid[i][j];
                col[i + 1][j] = col[i][j] + grid[i][j];
                diag[i + 1][j + 1] = diag[i][j] + grid[i][j];
                anti[i + 1][j] = anti[i][j + 1] + grid[i][j];
            }
        }

        for (int k = min(m, n); k >= 1; k--) {
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {

                    int d1 = diag[i + k][j + k] - diag[i][j];
                    int d2 = anti[i + k][j] - anti[i][j + k];

                    if (d1 != d2) continue;

                    bool ok = true;

                    for (int r = i; r < i + k; r++) {
                        if (row[r][j + k] - row[r][j] != d1) {
                            ok = false;
                            break;
                        }
                    }

                    for (int c = j; c < j + k && ok; c++) {
                        if (col[i + k][c] - col[i][c] != d1) {
                            ok = false;
                            break;
                        }
                    }

                    if (ok) return k;
                }
            }
        }
        return 1;
    }
};
