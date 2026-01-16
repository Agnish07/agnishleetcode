class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        vector<int> h = hFences;
        vector<int> v = vFences;

        h.push_back(1);
        h.push_back(m);
        v.push_back(1);
        v.push_back(n);

        sort(h.begin(), h.end());
        sort(v.begin(), v.end());
        unordered_set<int> st;

        for(int i = 0; i < h.size(); i++){
            for(int j = i+1; j < h.size();j++){
                st.insert(h[j]-h[i]);
            }
        }
        int maxi = -1;
        for(int i = 0; i < v.size(); i++){
            for(int j = i+1; j < v.size(); j++){
                int d = v[j]-v[i];
                if(st.count(d)){
                    maxi = max(maxi, d);
                }
            }
        }

        if(maxi == -1) return -1;
        int mod = 1e9+7;
        return (1LL*maxi*maxi) % mod;
    }
};