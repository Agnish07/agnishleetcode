class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int maxi = INT_MIN;

        for(int i = 0; i < n; i++){
            int len = 0;
            for(int j = i; j < n; j++){
                if(colors[i] != colors[j]) len = j-i;
            }
                maxi = max(len, maxi);
        }

        return maxi;
    }
};