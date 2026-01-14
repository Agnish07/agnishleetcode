class SegmentTree {
public:
    vector<int> xs, count;
    vector<long long> covered;
    int n;

    SegmentTree(const vector<int>& coords) {
        xs = coords;
        n = xs.size() - 1;
        count.assign(4 * n, 0);
        covered.assign(4 * n, 0);
    }

    void pull(int l, int r, int pos) {
        if (count[pos] > 0) {
            covered[pos] = (long long)xs[r + 1] - xs[l];
        } else if (l < r) {
            covered[pos] = covered[pos * 2 + 1] + covered[pos * 2 + 2];
        } else {
            covered[pos] = 0;
        }
    }

    void update(int ql, int qr, int val, int l, int r, int pos) {
        if (xs[r + 1] <= ql || xs[l] >= qr) return;
        if (ql <= xs[l] && xs[r + 1] <= qr) {
            count[pos] += val;
            pull(l, r, pos);
            return;
        }
        int mid = (l + r) / 2;
        update(ql, qr, val, l, mid, pos * 2 + 1);
        update(ql, qr, val, mid + 1, r, pos * 2 + 2);
        pull(l, r, pos);
    }
};

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        set<int> x_set;
        for (auto& sq : squares) {
            x_set.insert(sq[0]);
            x_set.insert(sq[0] + sq[2]);
        }

        vector<int> xs(x_set.begin(), x_set.end());
        SegmentTree st(xs);

        struct Event {
            double y;
            int type, x1, x2;
        };

        vector<Event> events;
        for (auto& sq : squares) {
            events.push_back({(double)sq[1], 1, sq[0], sq[0] + sq[2]});
            events.push_back({(double)sq[1] + sq[2], -1, sq[0], sq[0] + sq[2]});
        }

        sort(events.begin(), events.end(),
             [](const Event& a, const Event& b) { return a.y < b.y; });

        double totalArea = 0.0;
        vector<tuple<double, long long, double>> history;

        double prevY = events[0].y;
        for (auto& e : events) {
            double dy = e.y - prevY;
            if (dy > 0) {
                long long width = st.covered[0];
                totalArea += width * dy;
                history.emplace_back(dy, width, prevY);
            }
            st.update(e.x1, e.x2, e.type, 0, st.n - 1, 0);
            prevY = e.y;
        }

        double target = totalArea / 2.0;
        double currentArea = 0.0;

        for (auto& [dy, width, bottomY] : history) {
            double chunk = width * dy;
            if (currentArea + chunk >= target) {
                double need = target - currentArea;
                return bottomY + need / width;
            }
            currentArea += chunk;
        }

        return prevY;
    }
};
