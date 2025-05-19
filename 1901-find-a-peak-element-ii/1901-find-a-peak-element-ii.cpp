class Solution {
public:
    int findmaxincol(vector<vector<int>> &mat, int n, int m, int col){
        int maxval = -1;
        int index = 0;
        for(int i = 0; i < n; i++){
            if(mat[i][col] > maxval){
                maxval = mat[i][col];
                index = i;
            }
        }
        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int low = 0;
        int high = m-1;

        while(low <= high){
            int mid = low + ((high - low)/2);
            
            int row = findmaxincol(matrix,n,m,mid);

            int left = mid-1 >= 0 ? matrix[row][mid-1] : -1;
            int right = mid+1 < m ? matrix[row][mid+1] : -1;

            if(matrix[row][mid] > left && matrix[row][mid] > right) return {row, mid};
            else if(matrix[row][mid] < left) high = mid - 1;
            else low = mid + 1;

        }

        return{-1,-1};
    }
};