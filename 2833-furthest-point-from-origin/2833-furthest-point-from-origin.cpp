class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int m = 0;
        int extra = 0;
        for(auto &ch : moves){
            if(ch == 'L')m = m-1;
            else if (ch == 'R')m = m+1;
            else extra++;
        }

        if(m < 0) return -(m-extra);
        return m+extra;
    }
};