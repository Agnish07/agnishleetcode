class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;

        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        else if (dividend == INT_MIN && divisor == -1)
            return INT_MIN;
        else if (dividend == INT_MIN && divisor == 1)
            return INT_MIN;
        if (dividend == INT_MAX && divisor == 1)
            return INT_MAX;


        bool sign = true;
        if(dividend < 0 && divisor > 0) sign = false;
        else if(dividend >= 0 && divisor < 0) sign = false;

        long n = labs(dividend);
        long d = labs(divisor);

        long ans = 0;

        while(n >= d){
            int cnt = 0;

            while(n >= d << (cnt + 1) && (cnt + 1) < 31) cnt++;

            ans += (1<<cnt);
            n = n - d*(1<<cnt);
        }

        if (ans > INT_MAX) return INT_MAX;
        if (ans < INT_MIN) return INT_MIN;

        return sign ? ans : -ans;
    }
};