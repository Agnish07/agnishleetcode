class Solution {
public:
    long long minimumCost(string source, string target,
                          vector<string>& original,
                          vector<string>& changed,
                          vector<int>& cost) {
        int n = source.size();
        if (target.size() != n) return -1;

        // Collect all unique strings
        unordered_map<string,int> id;
        vector<string> strs;
        auto getId = [&](const string& s){
            if (!id.count(s)) {
                id[s] = strs.size();
                strs.push_back(s);
            }
            return id[s];
        };

        for (int i = 0; i < (int)original.size(); i++) {
            getId(original[i]);
            getId(changed[i]);
        }

        int m = strs.size();
        const long long INF = LLONG_MAX / 4;
        vector<vector<long long>> dist(m, vector<long long>(m, INF));
        for (int i = 0; i < m; i++) dist[i][i] = 0;

        // Direct conversions
        for (int i = 0; i < (int)original.size(); i++) {
            int u = getId(original[i]);
            int v = getId(changed[i]);
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        // Floyd–Warshall on string graph
        for (int k = 0; k < m; k++)
            for (int i = 0; i < m; i++)
                if (dist[i][k] < INF)
                    for (int j = 0; j < m; j++)
                        if (dist[k][j] < INF)
                            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        // Trie for originals
        struct Trie {
            int nxt[26];
            int sid;
            Trie() {
                memset(nxt, -1, sizeof(nxt));
                sid = -1;
            }
        };
        vector<Trie> trie(1);

        auto insertTrie = [&](const string& s){
            int cur = 0;
            for (char c : s) {
                int x = c - 'a';
                if (trie[cur].nxt[x] == -1) {
                    trie[cur].nxt[x] = trie.size();
                    trie.emplace_back();
                }
                cur = trie[cur].nxt[x];
            }
            trie[cur].sid = getId(s);
        };

        for (auto &s : original) insertTrie(s);

        // DP over positions
        vector<long long> dp(n + 1, INF);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            if (dp[i] == INF) continue;

            // Option: no operation if chars already equal
            if (source[i] == target[i]) {
                dp[i + 1] = min(dp[i + 1], dp[i]);
            }

            // Try substrings starting at i
            int cur = 0;
            for (int j = i; j < n; j++) {
                int x = source[j] - 'a';
                if (trie[cur].nxt[x] == -1) break;
                cur = trie[cur].nxt[x];

                if (trie[cur].sid != -1) {
                    int len = j - i + 1;
                    string tgtSub = target.substr(i, len);
                    if (!id.count(tgtSub)) continue;
                    int u = trie[cur].sid;
                    int v = id[tgtSub];
                    if (dist[u][v] < INF) {
                        dp[j + 1] = min(dp[j + 1], dp[i] + dist[u][v]);
                    }
                }
            }
        }

        return dp[n] == INF ? -1 : dp[n];
    }
};
