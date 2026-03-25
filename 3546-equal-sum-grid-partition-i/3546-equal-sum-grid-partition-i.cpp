class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<long long> rowsum(n, 0);
        vector<long long> colsum(m, 0);
        long long totsum = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                rowsum[i] += grid[i][j];
                colsum[j] += grid[i][j];
                totsum += grid[i][j];
            }
        }

        if(totsum%2 != 0) return false;
        
        long long rsum = 0;
        long long csum = 0;
        
        for(int i = 0; i < n; i++){
            rsum += rowsum[i];
            if(totsum/2 == rsum) return true;
        }

        for(int j = 0; j < m; j++){
            csum += colsum[j];
            if(totsum/2 == csum) return true;
        }

        return false;
    }
};