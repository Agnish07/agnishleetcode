class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long nn = n;

        if(nn < 0) nn = -1*nn;

        while(nn > 0){
            if(nn%2 == 1){
                nn = nn-1;
                ans *= x;
            }
            else{
                nn = nn/2;
                x = x*x;
            }
        }
            return (n < 0) ? 1.0/ans : ans;
    }
};