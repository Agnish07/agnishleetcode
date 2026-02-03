class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int fr = 0;
        int lr = n-1;
        int rr = -1;
        while(fr <= lr){
            int mr = (fr+lr)/2;

            if(target >= matrix[mr][0] && target <= matrix[mr][m-1]){
                rr = mr;
                break;
            }

            else if(target < matrix[mr][0]){
                lr = mr-1;
            }
            else{
                fr = mr+1;
            }
        }
        if(rr == -1) return false;
        int low = 0;
        int high = m-1;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(matrix[rr][mid] == target) return true;
            else if(matrix[rr][mid] < target) low = mid+1;
            else high = mid-1;
        }

        return false;
    }
};