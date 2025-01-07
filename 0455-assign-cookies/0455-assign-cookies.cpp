class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int n = g.size();
        int m = s.size();

        int curr = 0;
        int total = 0;

        for(int i = 0; i < n; i++){
            while(curr < m && g[i] > s[curr]){
                curr++;
            }
            if(curr < m ){
                total++;
                curr++;
            }
        }
        return total;
    }
};