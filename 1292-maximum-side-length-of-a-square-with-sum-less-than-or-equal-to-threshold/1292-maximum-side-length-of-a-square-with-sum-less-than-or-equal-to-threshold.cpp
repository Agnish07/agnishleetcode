class Solution {
public:

    bool check(vector<vector<int>> &mat,int size,vector<vector<int>> &rowsum, int threshold,int row,int col){
        int sum = 0;
        for(int i = row; i < row+size; i++){
            sum += rowsum[i][col+size] - rowsum[i][col];
            if(sum > threshold) return false;
        }
        return true;
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> rowsum(n, vector<int>(m+1, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                rowsum[i][j+1] = rowsum[i][j] + mat[i][j];
            }
        }

        int low = 1, high = min(m,n);
        int ans = 0;

        while(low <= high){
            int mid = (low+high)/2;

            bool found = false;

            for(int i = 0; i+mid <= n ; i++){
                for(int j = 0; j+mid <= m; j++){
                    if(check(mat,mid, rowsum, threshold, i, j)){
                        found = true;
                    break;
                    }
                }
            }

            if(found){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }

        return ans;

    }
};