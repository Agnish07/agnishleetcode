class DisjointSet{
public: 
    vector<int> size, parent;

    DisjointSet(int n){
        size.resize(n+1, 1);
        parent.resize(n+1);

        for(int i = 0; i <= n; i++) parent[i] = i;
    }

    int findUParent(int n){
        if(parent[n] == n) return n;
        return parent[n] = findUParent(parent[n]);
    }

    void unionBySize(int u, int v){
        int up_u = findUParent(u);
        int up_v = findUParent(v);

        if(up_u == up_v) return;

        int size_u = size[up_u];
        int size_v = size[up_v];

        if(size_u < size_v){
            parent[up_u] = up_v;
            size[up_v] += size_u;
        }
        else{
            parent[up_v] = up_u;
            size[up_u] += size_v;
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxr = 0;
        int maxc = 0;
        for(auto it : stones){
            maxr = max(maxr, it[0]);
            maxc = max(maxc, it[1]);
        }
        DisjointSet ds(maxr+maxc+1);
        unordered_map<int,int> mpp;

        for(auto it : stones){
            int rnode = it[0];
            int cnode = it[1] + maxr + 1;
            ds.unionBySize(rnode, cnode);
            mpp[rnode] = 1;
            mpp[cnode] = 1;
        }

        int cnt = 0;
        for(auto it : mpp){
            if(ds.findUParent(it.first) == it.first) cnt++;
        }

        return n-cnt;
    }
};