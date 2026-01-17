class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size(); 
        long long maxi = INT_MIN;

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int left = max(bottomLeft[i][0], bottomLeft[j][0]);
                int right = min(topRight[i][0], topRight[j][0]);
                int top = min(topRight[i][1], topRight[j][1]);
                int bottom = max(bottomLeft[i][1], bottomLeft[j][1]);

                if(left < right && top > bottom){
                    int side = min(top-bottom, right-left);
                    maxi = max(maxi, (1LL*side*side));
                }
            }
        }
        return maxi == INT_MIN ? 0 : maxi;
    }
};