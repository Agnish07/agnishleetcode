class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = 0;
        int mini = INT_MAX;
        long long neg = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i < n; i++){
            for (int j = 0; j < m; j++ ){
                if(matrix[i][j] < 0) neg++;
                ans += abs(matrix[i][j]);
                mini = min(mini, abs(matrix[i][j]));
            }
        }

        if(neg % 2 != 0){
            ans -= 2LL * mini;
        }

        return ans;
    }
};