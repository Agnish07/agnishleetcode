class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> graph(n);

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            graph[u].push_back({v, w});       // normal edge
            graph[v].push_back({u, 2 * w});   // reversed edge
        }

        const int INF = 1e9;
        vector<int> dist(n, INF);
        dist[0] = 0;

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<>
        > pq;

        pq.push({0, 0});

        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();

            if (cost > dist[u]) continue;
            if (u == n - 1) return cost;

            for (auto [v, w] : graph[u]) {
                if (cost + w < dist[v]) {
                    dist[v] = cost + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return -1;
    }
};
