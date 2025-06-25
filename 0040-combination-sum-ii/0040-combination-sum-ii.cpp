class Solution {
public:

    void func(int ind, int target, vector<vector<int>> &ans, vector<int> &ds, vector<int> &arr, int n){
        if(target == 0){
            ans.push_back(ds);
            return;
        }

        for(int i = ind; i < n; i ++){
            if(i > ind && arr[i] == arr[i-1]) continue;
            if(arr[i] > target) break;

            ds.push_back(arr[i]);
            func(i + 1, target - arr[i], ans, ds, arr, n);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        int n = candidates.size();
        func(0,target,ans,ds, candidates, n);
        return ans;
    }
};