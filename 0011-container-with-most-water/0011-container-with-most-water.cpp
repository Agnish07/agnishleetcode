class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1 ;
        int res = 0;
        int area;
        while(l < r){
            area = min(height[l], height[r]) * (r - l);
            res = max(res, area);

            if(height[l] <= height[r]){
                l++;
            }
            else{
                r--;
            }

        }
        return res;
    }
};