class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxa = 0;

        for(int r = 0; r < n; r++){
            for(int c = 0; c < m; c++){
                if(matrix[r][c] == 1 && r > 0){
                    matrix[r][c] += matrix[r-1][c];
                }
            }

            vector<int> heights = matrix[r];
            sort(heights.begin(), heights.end(), greater<int>());

            for(int i = 0; i < m; i++){
                int x = heights[i];
                int y = i+1;
                int ar = x*y;
                maxa = max(maxa, ar);
            }
        }
        return maxa;
    }
};