class Solution {
public:
    vector<vector<long long>> floyd(vector<vector<pair<int,int>>> &graph){
        vector<vector<long long>> dist(26, vector<long long>(26, INT_MAX));
        for(int i = 0; i < 26; i++){
            dist[i][i] = 0;
        }

        for(int i = 0; i < 26; i++){
            for(auto it : graph[i]){
                dist[i][it.first] = min(dist[i][it.first], (long long)it.second);
            }
        }
        

        for(int k = 0; k < 26; k++){
            for(int i = 0; i < 26; i++){
                for(int j = 0; j < 26; j++){
                    if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX){
                        dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                    }
                }
            }
        }
        return dist;
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<pair<int,int>>> graph(26);
        for(int i = 0; i < cost.size();i++){
            int u = original[i]-'a';
            int v = changed[i]-'a';
            int w = cost[i];

            graph[u].push_back({v,w});
        }
        vector<vector<long long>> dist = floyd(graph);
        long long total = 0;

        for(int i = 0; i < target.size();i++){
            int src = source[i] - 'a';
            int dest = target[i] - 'a';

            if(source[i] != target[i]){
                if(dist[src][dest] == INT_MAX) return -1;
                total += dist[src][dest];
            }
        }
        return total;
    }
};