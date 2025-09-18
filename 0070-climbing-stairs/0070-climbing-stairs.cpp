class Solution {
public:
    int f(int n, vector<int> &memo){
        if(n == 0 || n == 1) return 1;

        if(memo[n] != -1) return memo[n];

        int one = f(n-1, memo);
        int two = f(n-2, memo);

        return memo[n] = one + two;
    }
    int climbStairs(int n) {
        vector<int> memo(n+1,-1);
        return f(n, memo);
    }
};