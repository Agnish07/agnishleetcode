class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int m = nums.size();
        int n = m / 2;
        long long total = 0;
        for (int x : nums) total += x;

        vector<vector<long long>> sums1(n + 1), sums2(n + 1);
        for (int mask = 0; mask < (1 << n); ++mask) {
            int cnt = __builtin_popcount(mask);
            long long s = 0;
            for (int i = 0; i < n; ++i) if (mask & (1 << i)) s += nums[i];
            sums1[cnt].push_back(s);
        }
        for (int mask = 0; mask < (1 << n); ++mask) {
            int cnt = __builtin_popcount(mask);
            long long s = 0;
            for (int i = 0; i < n; ++i) if (mask & (1 << i)) s += nums[n + i];
            sums2[cnt].push_back(s);
        }
        for (int k = 0; k <= n; ++k) sort(sums2[k].begin(), sums2[k].end());

        long long best = LLONG_MAX, half = total / 2;
        for (int k = 0; k <= n; ++k) {
            int need = n - k;
            for (long long s1 : sums1[k]) {
                long long target = half - s1;
                auto& vec = sums2[need];
                auto it = lower_bound(vec.begin(), vec.end(), target);
                if (it != vec.end()) best = min(best, llabs(total - 2 * (s1 + *it)));
                if (it != vec.begin()) {
                    --it;
                    best = min(best, llabs(total - 2 * (s1 + *it)));
                }
            }
        }
        return (int)best;
    }
};
