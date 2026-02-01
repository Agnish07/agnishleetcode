class Solution {
public:
    vector<int> ncrow(int r){
        long long ans = 1;
        vector<int> ansr;
        ansr.push_back(1);
        for(int i = 1; i < r; i++){
            ans = ans*(r-i);
            ans = ans/i;
            ansr.push_back(ans);
        }
        return ansr;
    }
    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        vector<vector<int>> ans;
        for(int i = 1; i <= n; i++){
            vector<int> temp = ncrow(i);
            ans.push_back(temp);
            }
        return ans;
    }
};