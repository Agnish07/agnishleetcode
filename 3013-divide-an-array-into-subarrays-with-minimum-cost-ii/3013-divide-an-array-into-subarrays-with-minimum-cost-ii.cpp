class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        long long ans = LLONG_MAX;

        multiset<long long> small, large;
        long long sumSmall = 0;

        auto add = [&](long long x) {
            if (small.size() < k - 1) {
                small.insert(x);
                sumSmall += x;
            } else if (!small.empty() && x < *small.rbegin()) {
                large.insert(*small.rbegin());
                sumSmall -= *small.rbegin();
                small.erase(prev(small.end()));
                small.insert(x);
                sumSmall += x;
            } else {
                large.insert(x);
            }
        };

        auto remove = [&](long long x) {
            if (small.find(x) != small.end()) {
                small.erase(small.find(x));
                sumSmall -= x;
                if (!large.empty()) {
                    small.insert(*large.begin());
                    sumSmall += *large.begin();
                    large.erase(large.begin());
                }
            } else {
                large.erase(large.find(x));
            }
        };

        int L = 1;
        for (int R = 1; R < n; R++) {
            add(nums[R]);

            if (R - L + 1 > dist + 1) {
                remove(nums[L]);
                L++;
            }

            if (small.size() == k - 1) {
                ans = min(ans, nums[0] + sumSmall);
            }
        }

        return ans;
    }
};
