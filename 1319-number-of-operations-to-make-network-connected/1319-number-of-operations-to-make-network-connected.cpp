class DisjointSet {
public:
    vector<int> size, rank, parent;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int up_u = findUParent(u);
        int up_v = findUParent(v);

        if (up_u == up_v)
            return;

        int size_u = rank[up_u];
        int size_v = rank[up_v];

        if (size_u < size_v)
            parent[up_u] = up_v;
        else if (size_v < size_u)
            parent[up_v] = up_u;
        else {
            parent[up_v] = up_u;
            rank[up_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int up_u = findUParent(u);
        int up_v = findUParent(v);

        if (up_u == up_v)
            return;

        int size_u = size[up_u];
        int size_v = size[up_v];

        if (size_u < size_v) {
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        } else {
            parent[up_v] = up_u;
            size[up_u] += size[up_v];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extras = 0;

        for(auto it : connections){
            int u = it[0];
            int v = it[1];

            if(ds.findUParent(u) == ds.findUParent(v)){
                extras++;
            }

            else ds.unionBySize(u,v);
        }
        int nC = 0;
        for(int i=0; i<n ;i++){
            if(ds.parent[i] == i) nC++;
        }

        int ans = nC - 1;
        return ans <= extras ? ans : -1;
    }
};