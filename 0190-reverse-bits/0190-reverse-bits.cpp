class Solution {
public:
    int reverseBits(int n) {
        int res = 1;

        for(int i = 0; i < 32; i++){
            res = res << 1;

            if(n%2 == 1){
                res++;
            }

            n = n >> 1;
        }

        return res;
    }
};