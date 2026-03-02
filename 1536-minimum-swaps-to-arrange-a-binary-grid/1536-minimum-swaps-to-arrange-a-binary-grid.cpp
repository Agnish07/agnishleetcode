class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> zeros(n);

        for(int i = 0; i < n; i++){
            int zer = 0;
            for(int j = n-1; j >= 0; j--){
                if(grid[i][j] != 0) break;
                else zer++;
                zeros[i] = zer;
            }
        }

        int ans = 0;

        for(int i = 0; i < n; i++){
            int need = n-i-1;

            int j = i;
            while(j < n && zeros[j] < need){
                j++;
            }
            if(j == n) return -1;
            ans += j-i;
            while(j > i){
                swap(zeros[j], zeros[j-1]);
                j--;
            }
        }

        return ans;
    }
};