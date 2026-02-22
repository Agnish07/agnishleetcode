class Solution {
public:
    int binaryGap(int n) {
        int x = n;
        int maxi = 0;
        int lastpos = -1;
        int ind = 0;

        while(x > 0){
            int last = x&1;
            if(last == 1){
                if(lastpos != -1){
                    maxi = max(maxi, ind-lastpos);
                }
                lastpos = ind;
            }
            x = x >> 1;
            ind++;
        }
        return maxi;
    }
};