class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        int mod = 1e9 + 7;

        for(auto it : roads){
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        vector<long long> dist(n,LLONG_MAX);
        vector<int> ways(n,0);

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0,0});

        while(!pq.empty()){
            auto [dis, node] = pq.top();
            pq.pop();

            if(dis > dist[node]) continue;

            for(auto it : adj[node]){
                int adjN = it.first;
                long long edW = it.second;

                long long newDist = dis + edW;

                if(newDist < dist[adjN]){
                    dist[adjN] = newDist;
                    ways[adjN] = ways[node];
                    pq.push({newDist, adjN});
                }
                else if(newDist == dist[adjN]){
                    ways[adjN] = (ways[adjN] + ways[node]) % mod;
                }
            }
        }

        return ways[n-1];
    }
};
