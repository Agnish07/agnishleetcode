class Solution {
public:

    void func(int ind, int sum, vector<vector<int>> &ans, vector<int> &ds, int k, int n){

        if(ind > 9){
            if(k == 0){
                if(sum == n){
                    ans.push_back(ds);
                }
            }
                return;
        }

        if(sum > n || ind > 9) return;

        ds.push_back(ind);
        func(ind + 1, sum + ind, ans, ds, k - 1, n);
        ds.pop_back();
        func(ind + 1, sum, ans, ds, k, n);

    }

    vector<vector<int>> combinationSum3(int k, int n) {

        vector<vector<int>> ans;
        vector<int> ds;

        func(1, 0, ans, ds, k, n);

        return ans;
    }
};