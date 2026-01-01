class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // Adjacency list: node -> {adjNode, edgeWeight}
        vector<vector<pair<int,int>>> adj(n + 1);
        for (auto &t : times) {
            adj[t[0]].push_back({t[1], t[2]});
        }

        set<pair<int,int>> st;  // {distance, node}
        vector<int> dist(n + 1, 1e9);

        st.insert({0, k});
        dist[k] = 0;

        while (!st.empty()) {
            auto it = *st.begin();
            st.erase(st.begin());

            int node = it.second;
            int dis = it.first;

            for (auto &edge : adj[node]) {
                int adjNode = edge.first;
                int edgW = edge.second;

                if (dis + edgW < dist[adjNode]) {
                    if (dist[adjNode] != 1e9)
                        st.erase({dist[adjNode], adjNode});

                    dist[adjNode] = dis + edgW;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == 1e9) return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};
