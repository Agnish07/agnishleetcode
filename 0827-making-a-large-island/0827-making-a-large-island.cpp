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
    bool isValid(int newr, int newc,int n){
        return newr >= 0 && newr < n && newc >= 0 && newc < n;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);

        //step 1 - connecting components
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 0) continue;

                int dr[] = {-1, 0, +1, 0};
                int dc[] = {0, -1, 0, +1};

                for(int ind = 0; ind <= 3; ind++){
                    int newr = row + dr[ind];
                    int newc = col + dc[ind];

                    if(isValid(newr, newc, n) && grid[newr][newc] == 1){
                        int nodeno = row*n+col;
                        int adjn = newr * n + newc;
                        ds.unionBySize(nodeno, adjn);

                    }
                }
            }
        }

        // step 2 - brute force (try and convert every 0 to 1)
        int maxi = 0;
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 1) continue;

                int dr[] = {-1, 0, +1, 0};
                int dc[] = {0, -1, 0, +1};

                set<int> components;

                for(int ind = 0; ind <= 3; ind++){
                    int newr = row + dr[ind];
                    int newc = col + dc[ind];

                    if(isValid(newr, newc, n)){
                        if(grid[newr][newc] == 1){
                            components.insert(ds.findUParent(newr * n + newc));
                        }

                    }
                }
                int sizetotal = 1;
                for(auto it : components){
                    sizetotal += ds.size[it];
                }
                maxi = max(maxi, sizetotal);
            }
        }

        for(int cell = 0; cell < n*n; cell++){
            maxi = max(maxi, ds.size[ds.findUParent(cell)]);
        }
        return maxi;
    }
};