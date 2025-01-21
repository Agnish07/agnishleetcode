class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int ans = 0;
        for(vector<int>& row : grid){
            ranges::sort(row);
        } 

        for(int j = 0; j < grid[0].size(); j++){
                int maxofcolumn = 0;
            for(int i = 0; i < grid.size(); i++){
                maxofcolumn = max(maxofcolumn, grid[i][j]);
            }
                ans += maxofcolumn;
        }
        return ans;
    }
};