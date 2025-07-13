class Solution {
public:
    int trap(vector<int>& height) {
        int total = 0;
        int r = height.size()-1;
        int l = 0;
        int lmax = 0;
        int rmax = 0;

        while(l < r){
            if(height[l] <= height[r]){
                if(lmax > height[l]){
                    total += lmax - height[l];
                }
                else{
                    lmax = height[l];
                }
                l++;
            }
            else{
                if(rmax > height[r]){
                    total += rmax - height[r];
                }
                else{
                    rmax = height[r];
                }
                r--;
            }
        }
        return total;
    }
};