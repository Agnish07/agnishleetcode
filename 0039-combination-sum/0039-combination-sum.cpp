class Solution {
public:
    void func(int ind, int t,vector<int> &ds, vector<vector<int>> &ans, vector<int> &arr, int n){
        if(ind == n){
            if(t == 0){
                ans.push_back(ds);
            }
            return ;
        }

        if(arr[ind] <= t){
            ds.push_back(arr[ind]);
            func(ind, t - arr[ind], ds, ans,arr, n);
            ds.pop_back();
        }
        func(ind+1, t, ds, ans, arr, n);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = candidates.size();
        func(0,target, ds, ans, candidates,n);
        return ans;
    }
};