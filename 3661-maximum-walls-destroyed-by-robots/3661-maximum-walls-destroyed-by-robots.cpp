class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& dist, vector<int>& walls) {
        int n = robots.size();

        vector<pair<int, int>> bot(n);
        for (int i = 0; i < n; i++) {
            bot[i] = {robots[i], dist[i]};
        }

        sort(bot.begin(), bot.end());
        sort(walls.begin(), walls.end());


        bot.push_back({(int)1e9, 0});

        auto countWalls = [&](int l, int r) {
            if (l > r) return 0;
            auto right = upper_bound(walls.begin(), walls.end(), r);
            auto left  = lower_bound(walls.begin(), walls.end(), l);
            return (int)(right - left);
        };

        vector<vector<int>> dp(n, vector<int>(2, 0));

        dp[0][0] = countWalls(bot[0].first - bot[0].second, bot[0].first);

        if (n > 1) {
            dp[0][1] = countWalls(
                bot[0].first,
                min(bot[1].first - 1, bot[0].first + bot[0].second)
            );
        } else {
            dp[0][1] = countWalls(
                bot[0].first,
                bot[0].first + bot[0].second
            );
        }

        for (int i = 1; i < n; i++) {

            int pos = bot[i].first;
            int d   = bot[i].second;

            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) +
                       countWalls(
                           pos,
                           min(bot[i + 1].first - 1, pos + d)
                       );

            int leftStart = max(pos - d, bot[i - 1].first + 1);
            int leftEnd   = pos;

            dp[i][0] = dp[i - 1][0] +
                       countWalls(leftStart, leftEnd);

            int overlapStart = leftStart;
            int overlapEnd   = min(bot[i - 1].first + bot[i - 1].second, pos - 1);

            int overlapFix =
                dp[i - 1][1]
                + countWalls(leftStart, leftEnd)
                - countWalls(overlapStart, overlapEnd);

            dp[i][0] = max(dp[i][0], overlapFix);
        }

        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};