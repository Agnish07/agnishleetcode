class Solution {
public:
    bool hasAlternatingBits(int n) {
        int x = n;
        int last = x & 1;
        x = x>>1;

        while(x > 0){
            if((x & 1) == last) return false;
            last = x & 1;
            x = x>>1;
        }

        return true;
    }
};