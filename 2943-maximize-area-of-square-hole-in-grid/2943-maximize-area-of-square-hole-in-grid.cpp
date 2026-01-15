class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int cnt1 = 1, cnt2 = 1, max1 = 1, max2 = 1;

        for(int i = 1; i < hBars.size(); i++){
            if(hBars[i]-1 == hBars[i-1]) cnt1++;
            else{
                cnt1 = 1;
            }
                max1 = max(max1, cnt1);
        }

        for(int i = 1; i < vBars.size(); i++){
            if(vBars[i]-1 == vBars[i-1]) cnt2++;
            else{
                cnt2 = 1;
            }
                max2 = max(max2, cnt2);
        }

        int side = min(max1+1, max2+1);
        return side*side;

    }
};