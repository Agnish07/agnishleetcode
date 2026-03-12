class DSU {
public:
    vector<int> p;
    DSU(int n) { p.resize(n); iota(p.begin(), p.end(), 0); }
    DSU(vector<int> x) : p(x) {}
    
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    void join(int a, int b) { a = find(a); b = find(b); if (a != b) p[a] = b; }
};

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& e, int k) {
        if (e.size() < n - 1) return -1;

        vector<vector<int>> must, opt;
        for (auto &x : e) (x[3] ? must : opt).push_back(x);

        if (must.size() > n - 1) return -1;

        sort(opt.begin(), opt.end(), [](auto &a, auto &b){ return a[2] > b[2]; });

        DSU d(n);
        int used = 0, mn = 2e5;

        for (auto &x : must) {
            if (d.find(x[0]) == d.find(x[1])) return -1;
            d.join(x[0], x[1]);
            used++;
            mn = min(mn, x[2]);
        }

        int l = 0, r = mn, ans = -1;

        while (l <= r) {
            int mid = (l + r) / 2;
            DSU t(d.p);
            int cnt = used, dbl = 0;

            for (auto &x : opt) {
                if (t.find(x[0]) == t.find(x[1])) continue;

                if (x[2] >= mid || (dbl < k && x[2] * 2 >= mid)) {
                    if (x[2] < mid) dbl++;
                    t.join(x[0], x[1]);
                    cnt++;
                } else break;

                if (cnt == n - 1) break;
            }

            if (cnt == n - 1) ans = mid, l = mid + 1;
            else r = mid - 1;
        }

        return ans;
    }
};